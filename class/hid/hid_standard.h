#pragma once

#include <stdint.h>

enum
{
	HID_INTERFACE_CLASS = 0x03,
	HID_INTERFACE_SUBCLASS = 0x00
};

typedef enum
{
	USB_HID_REQ_GetReport = 1,
	USB_HID_REQ_GetIdle = 2,
	USB_HID_REQ_GetProtocol = 3,
	USB_HID_REQ_SetReport = 9,
	USB_HID_REQ_SetIdle = 10,
	USB_HID_REQ_SetProtocol = 11
} USB_HID_Request;

typedef enum
{
	USB_HID_REPORT_INPUT = 1,
	USB_HID_REPORT_OUTPUT = 2,
	USB_HID_REPORT_FEATURE = 3
} USB_HID_Request_ReportType;

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
