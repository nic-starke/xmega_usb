#pragma once

#include <stdint.h>

enum
{
	AUDIO_INTERFACE_CLASS = 0x01
};

enum
{
	AUDIOCONTROL_INTERFACE_SUBCLASS = 0x01,
	AUDIOSTREAMING_INTERFACE_SUBCLASS = 0x02,
	MIDISTREAMING_INTERFACE_SUBCLASS = 0x03
};

typedef enum
{
	USB_AUDIO_CS_UNDEFINED = 0x20,
	USB_AUDIO_CS_DEVICE = 0x21,
	USB_AUDIO_CS_CONFIGURATION = 0x22,
	USB_AUDIO_CS_STRING = 0x23,
	USB_AUDIO_CS_INTERFACE = 0x24,
	USB_AUDIO_CS_ENDPOINT = 0x25
} USB_AUDIO_dtype;

typedef enum
{
	USB_AC_IF_DSUBTYPE_HEADER = 0x01,
	USB_AC_IF_DSUBTYPE_INPUT_TERMINAL = 0x02,
	USB_AC_IF_DSUBTYPE_OUTPUT_TERMINAL = 0x03,
	USB_AC_IF_DSUBTYPE_MIXER_UNIT = 0x04,
	USB_AC_IF_DSUBTYPE_SELECTOR_UNIT = 0x05,
	USB_AC_IF_DSUBTYPE_FEATURE_UNIT = 0x06,
	USB_AC_IF_DSUBTYPE_PROCESSING_UNIT = 0x07,
	USB_AC_IF_DSUBTYPE_EXTENSION_UNIT = 0x08
} USB_AC_IF_dsubtype;

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
} __attribute__ ((packed)) USB_Audio_StdEndpointDescriptor;

// Audio control
typedef struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubType;
	uint16_t bcdADC;
	uint16_t wTotalLength;
	uint8_t bInCollection;
	uint8_t baInterfaceNr[];
} __attribute__ ((packed)) USB_AudioControl_CSInterfaceHeaderDescriptor;

