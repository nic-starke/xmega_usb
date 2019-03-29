#pragma once

#include <stdint.h>

#define AUDIO_INTERFACE_CLASS 0x01

typedef struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bEndpointAddress;
	uint8_t bmAttributes;
	uint16_t wMaxPacketSize;
	uint8_t bInterval;
	uint8_t bRefresh;
	uint8_t bSynchAddress;
} __attribute__ ((packed)) USB_Audio_EndpointDescriptor;
