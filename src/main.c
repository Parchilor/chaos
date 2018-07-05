#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "MQTTPacket.h"
#include "transport.h"

#include <signal.h>


#define MQTT_CONF_INIT(data, cid, alive, cs, user, pw) \
	do{ \
	data.clientID.cstring = cid; \
	data.keepAliveInterval = alive; \
	data.cleansession = cs; \
	data.username.cstring = user; \
	data.password.cstring = pw; \
	}while(0)

int toStop = 0;

int MQTT_subscribe(int mysock, char *topic);
void publish_test(int);

void cfinish(int sig)
{
	signal(SIGINT, NULL);
	toStop = 1;
}

void stop_init(void)
{
	signal(SIGINT, cfinish);
	signal(SIGTERM, cfinish);
}

int main(int argc, char *argv[])
{
	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
//	MQTTString topicString = MQTTString_initializer;
	int rc;
	int mysock = 0;
	unsigned char buf[200];
	int buflen = sizeof(buf);
//	int msgid = 1;
//	int req_qos = 0;
//	char *payload = "mypayload";
//	int palyloadlen = strlen(payload);
	int len = 0;
	char *host = "192.168.1.188";
	int port = 1883;

	stop_init();
	if (argc > 1)
		host = argv[1];

	if (argc > 2)
		port = atoi(argv[2]);

	mysock = transport_open(host, port);
	if(mysock < 0)
		return mysock;

	printf("Will connect to hostname [%s] port <%d>\n", host, port);
/*
	data.clientID.cstring = "Router";
	data.keepAliveInterval = 8;
	data.cleansession = 1;
	data.username.cstring = "root";
	data.password.cstring = "root";
*/
	MQTT_CONF_INIT(data, "Router", 8, 1, "root", "root");

	len = MQTTSerialize_connect(buf, buflen, &data);
	rc = transport_sendPacketBuffer(mysock, buf, len);

	/* wait for connack */
	if (MQTTPacket_read(buf, buflen, transport_getdata) == CONNACK)
	{
		unsigned char sessionPresent, connack_rc;

		if (MQTTDeserialize_connack(&sessionPresent, &connack_rc, buf, buflen) != 1 || connack_rc != 0)
		{
			printf("Unable to connect.[%d]\n", connack_rc);
			goto exit;
		}
	}
	else
		goto exit;
	if(MQTT_subscribe(mysock, "DNF") == -1)
		goto exit;
	publish_test(mysock);

	printf("disconnecting\n");
	len = MQTTSerialize_disconnect(buf, buflen);
	rc = transport_sendPacketBuffer(mysock, buf, len);

exit:
	transport_close(mysock);

	return 0;
}

int MQTT_subscribe(int mysock, char *topic)
{
	MQTTString topicString = MQTTString_initializer;
	int rc = 0;
	unsigned char buf[200];
	int buflen = sizeof(buf);
	int msgid = 1;
	int req_qos = 0;
	int len = 0;

	/* subscribe */
	topicString.cstring = topic;//"substopic";
	len = MQTTSerialize_subscribe(buf, buflen, 0, msgid, 1, &topicString, &req_qos);

	rc = transport_sendPacketBuffer(mysock, buf, len);
	if (MQTTPacket_read(buf, buflen, transport_getdata) == SUBACK) 	/* wait for suback */
	{
		unsigned short submsgid;
		int subcount;
		int granted_qos;

		rc = MQTTDeserialize_suback(&submsgid, 1, &subcount, &granted_qos, buf, buflen);
		if (granted_qos != 0)
		{
			printf("granted qos != 0, %d\n", granted_qos);
			return -1;
		}
	}
	else
		return -1;
	return 0;
}

void publish_test(int mysock)
{
//	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
//	MQTTString topicString = MQTTString_initializer;
	int rc;
//	int mysock = 0;
	unsigned char buf[200];
	int buflen = sizeof(buf);
//	int msgid = 1;
//	int req_qos = 0;
//	char *payload = "mypayload";
//	int palyloadlen = strlen(payload);
	int len = 0;
//	char *host = "192.168.1.188";
//	int port = 1883;
	static int rl_times = 0;


	int cnt = 5;
	/* loop getting msgs on subscribed topic */
//	topicString.cstring = "pubtopic";
	while (!toStop)
	{
		/* transport_getdata() has a built-in 1 second timeout,
		your mileage will vary */
		if (MQTTPacket_read(buf, buflen, transport_getdata) == PUBLISH)
		{
			unsigned char dup;
			int qos;
			unsigned char retained;
			unsigned short msgid;
			int payloadlen_in;
			unsigned char* payload_in;
			MQTTString receivedTopic;

			rc = MQTTDeserialize_publish(&dup, &qos, &retained, &msgid, &receivedTopic,
					&payload_in, &payloadlen_in, buf, buflen);
			printf("MSG: %.*s\n", payloadlen_in, payload_in);
			if(!strncmp((char *)payload_in, "exit", payloadlen_in))
				break;
		}

		if(!cnt--)
		{
			unsigned char req[2];
			MQTTSerialize_pingreq(req, 2);
			rc = transport_sendPacketBuffer(mysock, req, 2);
			cnt = 5;
			if (MQTTPacket_read(buf, buflen, transport_getdata) == PINGRESP) 	/* wait for suback */
			{
				printf("Get PINGRESP!!!\n");
				continue;
			}
			else
			{
				printf("No PINGRESP!!!\n"
						"Out of line!!!\n");
				continue;
			//	break;
			}

		}
	}
}
