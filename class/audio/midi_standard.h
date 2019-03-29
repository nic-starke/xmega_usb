#pragma once

#include <stdint.h>

#include "audio_standard.h"

typedef enum
{
	USB_MIDI_IF_DSUBTYPE_HEADER = 0x01,
	USB_MIDI_IF_DSUBTYPE_MIDI_IN_JACK = 0x02,
	USB_MIDI_IF_DSUBTYPE_MIDI_OUT_JACK = 0x03,
	USB_MIDI_IF_DSUBTYPE_ELEMENT = 0x04
} USB_MIDI_ID_dsubtype;

typedef enum
{
	USB_MIDI_JACK_TYPE_EMBEDDED = 0x01,
	USB_MIDI_JACK_TYPE_EXTERNAL = 0x02
} USB_MIDI_JackType;

typedef enum
{
	USB_MIDI_EP_DSUBTYPE_GENERAL = 0x01
} USB_MIDI_EP_dsubtype;

typedef struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubType;	
	uint16_t bcdMSC;
	uint16_t wTotalLength;
} __attribute__ ((packed)) MIDIStreaming_CSInterfaceHeaderDescriptor;

typedef struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubType;	
	uint8_t bJackType;
	uint8_t bJackID;
	uint8_t iJack;
} __attribute__ ((packed)) MIDIStreaming_InJackDescriptor;

typedef struct
{
	uint8_t baSourceID;
	uint8_t baSourcePin;
} __attribute__ ((packed)) MIDIStreaming_SourceToPin;

typedef struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubType;
	uint8_t bJackType;
	uint8_t bJackID;
	uint8_t bNrInputPins;
	MIDIStreaming_SourceToPin aSourceToPins[];
} __attribute__ ((packed)) MIDIStreaming_OutJackDescriptorBegin;

typedef struct
{
	uint8_t iJack;
} __attribute__ ((packed)) MIDIStreaming_OutJackDescriptorEnd;

typedef struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubType;	
	uint8_t bElementID;
	uint8_t bNrInputPins;
	MIDIStreaming_SourceToPin aSourceToPins[];
} __attribute__ ((packed)) MIDIStreaming_ElementDescriptorBegin;

typedef struct
{
	uint8_t bNrOutputPins;
	uint8_t bInTerminalLink;
	uint8_t bOutTerminalLink;
	uint8_t bElCapsSize;
	uint8_t bmElementCaps[];
} __attribute__ ((packed)) MIDIStreaming_ElementDescriptorPart2;


typedef struct
{
	uint8_t iElement;
} __attribute__ ((packed)) MIDIStreaming_ElementDescriptorEnd;

typedef struct
{
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubType;
	uint8_t bNumEmbMIDIJack;
	uint8_t baAssocJackID[];
} __attribute__ ((packed)) USB_MidiStreaming_EndpointDescriptor;

