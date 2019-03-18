#pragma once

#include <stdint.h>

#define HID_INTERFACE_CLASS 0x03
#define HID_INTERFACE_SUBCLASS 0x00

typedef enum
{
	USB_HID_DTYPE_Hid = 0x21,
	USB_HID_DTYPE_HidReport = 0x22
} USB_HID_dtype;

typedef struct {
	uint8_t bDescriptorType;
	uint16_t wDescriptorLength;
} __attribute__ ((packed)) HID_DescritorList;

typedef struct {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint16_t bcdHID;
	uint8_t bCountryCode;
	uint8_t bNumDescriptors;
	uint8_t bReportDescriptorType;
	uint16_t wReportDescriptorLength;
} __attribute__ ((packed)) HID_Descriptor;
