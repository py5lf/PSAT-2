#ifdef INCLUDE_OV2640_REGS

#define BANK_SEL            0xFF
#define QS                  0x44
#define CTRLI               0x50
#define HSIZE               0x51
#define VSIZE               0x52
#define XOFFL               0x53
#define YOFFL               0x54
#define VHYX                0x55
#define TEST                0x57
#define ZMOW                0x5A
#define ZMOH                0x5B
#define ZMHH                0x5C
#define CTRL2               0x86
#define SIZEL               0x8C
#define HSIZE8              0xC0
#define VSIZE8              0xC1
#define R_DVP_SP            0xD3
#define RESET               0xE0

static const uint8_t OV2640_RESET[][2] =
{
    { BANK_SEL, BANK_SEL_SENSOR },
    { 0x12, 0x80 },
};

/*
    OV2640 Camera Module, Software Application Notes
    13.1.1 SVGA Preview
    OV2640_SVGA_YUV_AM 14.3 fps
    24 MHz input clock
*/
static const uint8_t OV2640_JPEG_INIT[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { 0x2c, 0xff },
    { 0x2e, 0xdf },

    { BANK_SEL, BANK_SEL_SENSOR },
    { 0x3c, 0x32 },
    { 0x11, 0x00 }, // CLKRC was 0x01
    { 0x09, 0x02 },
    { 0x04, 0x28 },
    { 0x13, 0xe5 },
    { 0x14, 0x48 },
    { 0x2c, 0x0c },
    { 0x33, 0x78 },
    { 0x3a, 0x33 },
    { 0x3b, 0xfb },
    { 0x3e, 0x00 },
    { 0x43, 0x11 },
    { 0x16, 0x10 },
    { 0x39, 0x92 },
    { 0x35, 0xda },
    { 0x22, 0x1a },
    { 0x37, 0xc3 },
    { 0x23, 0x00 },
    { 0x34, 0xc0 },
    { 0x36, 0x1a },
    { 0x06, 0x88 },
    { 0x07, 0xc0 },
    { 0x0d, 0x87 },
    { 0x0e, 0x41 },
    { 0x4c, 0x00 },
    { 0x48, 0x00 },
    { 0x5b, 0x00 },
    { 0x42, 0x03 },
    { 0x4a, 0x81 },
    { 0x21, 0x99 },
    { 0x24, 0x40 },
    { 0x25, 0x38 },
    { 0x26, 0x82 },
    { 0x5c, 0x00 },
    { 0x63, 0x00 },
    { 0x61, 0x70 },
    { 0x62, 0x80 },
    { 0x7c, 0x05 },
    { 0x20, 0x80 },
    { 0x28, 0x30 },
    { 0x6c, 0x00 },
    { 0x6d, 0x80 },
    { 0x6e, 0x00 },
    { 0x70, 0x02 },
    { 0x71, 0x94 },
    { 0x73, 0xc1 },
    { 0x12, 0x40 },
    { 0x17, 0x11 },
    { 0x18, 0x43 },
    { 0x19, 0x00 },
    { 0x1a, 0x4b },
    { 0x32, 0x09 },
    { 0x37, 0xc0 },
    { 0x4f, 0x60 },
    { 0x50, 0xa8 },
    { 0x6d, 0x00 },
    { 0x3d, 0x38 },
    { 0x46, 0x3f },
    { 0x4f, 0x60 },
    { 0x0c, 0x3c },

    { BANK_SEL, BANK_SEL_DSP },
    { 0xe5, 0x7f },
    { 0xf9, 0xc0 },
    { 0x41, 0x24 },
    { 0xe0, 0x14 },
    { 0x76, 0xff },
    { 0x33, 0xa0 },
    { 0x42, 0x20 },
    { 0x43, 0x18 },
    { 0x4c, 0x00 },
    { 0x87, 0xd5 },
    { 0x88, 0x3f },
    { 0xd7, 0x03 },
    { 0xd9, 0x10 },
    { 0xd3, 0x82 },
    { 0xc8, 0x08 },
    { 0xc9, 0x80 },
    { 0x7c, 0x00 },
    { 0x7d, 0x00 },
    { 0x7c, 0x03 },
    { 0x7d, 0x48 },
    { 0x7d, 0x48 },
    { 0x7c, 0x08 },
    { 0x7d, 0x20 },
    { 0x7d, 0x10 },
    { 0x7d, 0x0e },
    { 0x90, 0x00 },
    { 0x91, 0x0e },
    { 0x91, 0x1a },
    { 0x91, 0x31 },
    { 0x91, 0x5a },
    { 0x91, 0x69 },
    { 0x91, 0x75 },
    { 0x91, 0x7e },
    { 0x91, 0x88 },
    { 0x91, 0x8f },
    { 0x91, 0x96 },
    { 0x91, 0xa3 },
    { 0x91, 0xaf },
    { 0x91, 0xc4 },
    { 0x91, 0xd7 },
    { 0x91, 0xe8 },
    { 0x91, 0x20 },
    { 0x92, 0x00 },
    { 0x93, 0x06 },
    { 0x93, 0xe3 },
    { 0x93, 0x05 },
    { 0x93, 0x05 },
    { 0x93, 0x00 },
    { 0x93, 0x04 },
    { 0x93, 0x00 },
    { 0x93, 0x00 },
    { 0x93, 0x00 },
    { 0x93, 0x00 },
    { 0x93, 0x00 },
    { 0x93, 0x00 },
    { 0x93, 0x00 },
    { 0x96, 0x00 },
    { 0x97, 0x08 },
    { 0x97, 0x19 },
    { 0x97, 0x02 },
    { 0x97, 0x0c },
    { 0x97, 0x24 },
    { 0x97, 0x30 },
    { 0x97, 0x28 },
    { 0x97, 0x26 },
    { 0x97, 0x02 },
    { 0x97, 0x98 },
    { 0x97, 0x80 },
    { 0x97, 0x00 },
    { 0x97, 0x00 },
    { 0xc3, 0xed },
    { 0xa4, 0x00 },
    { 0xa8, 0x00 },
    { 0xc5, 0x11 },
    { 0xc6, 0x51 },
    { 0xbf, 0x80 },
    { 0xc7, 0x10 },
    { 0xb6, 0x66 },
    { 0xb8, 0xa5 },
    { 0xb7, 0x64 },
    { 0xb9, 0x7c },
    { 0xb3, 0xaf },
    { 0xb4, 0x97 },
    { 0xb5, 0xff },
    { 0xb0, 0xc5 },
    { 0xb1, 0x94 },
    { 0xb2, 0x0f },
    { 0xc4, 0x5c },
    { 0xc0, 0x64 },
    { 0xc1, 0x4b },
    { 0x8c, 0x00 },
    { 0x86, 0x3d },
    { 0x50, 0x00 },
    { 0x51, 0xc8 },
    { 0x52, 0x96 },
    { 0x53, 0x00 },
    { 0x54, 0x00 },
    { 0x55, 0x00 },
    { 0x5a, 0xc8 },
    { 0x5b, 0x96 },
    { 0x5c, 0x00 },
    { 0xd3, 0x00 }, // R_DVP_SP was 0x82
    { 0xc3, 0xed },
    { 0x7f, 0x00 },
    { 0xda, 0x00 },
    { 0xe5, 0x1f },
    { 0xe1, 0x67 },
    { 0xe0, 0x00 },
    { 0xdd, 0x7f },
    { 0x05, 0x00 },

    { 0, 0 }
};

static const uint8_t OV2640_JPEG_ON[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { 0xe0, 0x14 },
    { 0xe1, 0x77 },
    { 0xe5, 0x1f },
    { 0xd7, 0x03 },
    { 0xda, 0x10 },
    { 0xe0, 0x00 },

    { 0, 0 }
};

static const uint8_t OV2640_AWB_AUTO[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { 0xc7, 0x00 },

    { 0, 0 }
};

static const uint8_t OV2640_AWB_SUNNY[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { 0xc7, 0x40 },
    { 0xcc, 0x5e },
    { 0xcd, 0x41 },
    { 0xce, 0x54 },

    { 0, 0 }
};

static const uint8_t OV2640_AWB_CLOUDY[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { 0xc7, 0x40 },
    { 0xcc, 0x65 },
    { 0xcd, 0x41 },
    { 0xce, 0x4f },

    { 0, 0 }
};

static const uint8_t OV2640_AWB_OFFICE[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { 0xc7, 0x40 },
    { 0xcc, 0x52 },
    { 0xcd, 0x41 },
    { 0xce, 0x66 },

    { 0, 0 }
};

static const uint8_t OV2640_AWB_HOME[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { 0xc7, 0x40 },
    { 0xcc, 0x42 },
    { 0xcd, 0x3f },
    { 0xce, 0x71 },

    { 0, 0 }
};

static const uint8_t OV2640_SENSOR_SMALL[][2] =
{
    { BANK_SEL, BANK_SEL_SENSOR },
    { 0x12, 0x40 },
    { 0x17, 0x11 },
    { 0x18, 0x43 },
    { 0x19, 0x00 },
    { 0x1a, 0x4b },
    { 0x32, 0x09 },
    { 0x4f, 0xca },
    { 0x50, 0xa8 },
    { 0x5a, 0x23 },
    { 0x6d, 0x00 },
    { 0x39, 0x12 },
    { 0x35, 0xda },
    { 0x22, 0x1a },
    { 0x37, 0xc3 },
    { 0x23, 0x00 },
    { 0x34, 0xc0 },
    { 0x36, 0x1a },
    { 0x06, 0x88 },
    { 0x07, 0xc0 },
    { 0x0d, 0x87 },
    { 0x0e, 0x41 },
    { 0x4c, 0x00 },
    { 0, 0 }
};

static const uint8_t OV2640_SENSOR_LARGE[][2] =
{
    { BANK_SEL, BANK_SEL_SENSOR },
    { 0x11, 0x01 }, // CLKRC
    { 0x12, 0x00 },
    { 0x17, 0x11 },
    { 0x18, 0x75 },
    { 0x32, 0x36 },
    { 0x19, 0x01 },
    { 0x1a, 0x97 },
    { 0x03, 0x0f },
    { 0x37, 0x40 },
    { 0x4f, 0xbb },
    { 0x50, 0x9c },
    { 0x5a, 0x57 },
    { 0x6d, 0x80 },
    { 0x3d, 0x34 },
    { 0x39, 0x02 },
    { 0x35, 0x88 },
    { 0x22, 0x0a },
    { 0x37, 0x40 },
    { 0x34, 0xa0 },
    { 0x06, 0x02 },
    { 0x0d, 0xb7 },
    { 0x0e, 0x01 },
    { 0, 0 }
};

/* JPG 160x120 */
static const uint8_t OV2640_DSP_160x120[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { RESET, 0x04 },
    { HSIZE8, 0x64 },
    { VSIZE8, 0x4b },
    { CTRL2, 0x35 },
    { CTRLI, 0x92 },
    { HSIZE, 0xc8 },
    { VSIZE, 0x96 },
    { XOFFL, 0x00 },
    { YOFFL, 0x00 },
    { VHYX, 0x00 },
    { TEST, 0x00 },
    { ZMOW, 0x28 },
    { ZMOH, 0x1e },
    { ZMHH, 0x00 },
    { RESET, 0x00 },
    { 0, 0 }
};

/* JPG, 176x144 */
static const uint8_t OV2640_DSP_176x144[][2] =
{

    { BANK_SEL, BANK_SEL_DSP },
    { RESET, 0x04 },
    { HSIZE8, 0x64 },
    { VSIZE8, 0x4b },
    { CTRL2, 0x35 },
    { CTRLI, 0x92 },
    { HSIZE, 0xc8 },
    { VSIZE, 0x96 },
    { XOFFL, 0x00 },
    { YOFFL, 0x00 },
    { VHYX, 0x00 },
    { TEST, 0x00 },
    { ZMOW, 0x2c },
    { ZMOH, 0x24 },
    { ZMHH, 0x00 },
    { RESET, 0x00 },
    { 0, 0 }
};

/* JPG 320x240 */
static const uint8_t OV2640_DSP_320x240[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { RESET, 0x04 },
    { HSIZE8, 0x64 },
    { VSIZE8, 0x4b },
    { CTRL2, 0x35 },
    { CTRLI, 0x89 },
    { HSIZE, 0xc8 },
    { VSIZE, 0x96 },
    { XOFFL, 0x00 },
    { YOFFL, 0x00 },
    { VHYX, 0x00 },
    { TEST, 0x00 },
    { ZMOW, 0x50 },
    { ZMOH, 0x3c },
    { ZMHH, 0x00 },
    { RESET, 0x00 },
    { 0, 0 }
};

/* JPG 352x288 */
static const uint8_t OV2640_DSP_352x288[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { RESET, 0x04 },
    { HSIZE8, 0x64 },
    { VSIZE8, 0x4b },
    { CTRL2, 0x35 },
    { CTRLI, 0x89 },
    { HSIZE, 0xc8 },
    { VSIZE, 0x96 },
    { XOFFL, 0x00 },
    { YOFFL, 0x00 },
    { VHYX, 0x00 },
    { TEST, 0x00 },
    { ZMOW, 0x58 },
    { ZMOH, 0x48 },
    { ZMHH, 0x00 },
    { RESET, 0x00 },
    { 0, 0 }
};

/* JPG 640x480 */
static const uint8_t OV2640_DSP_640x480[][2] =
{

    { BANK_SEL, BANK_SEL_DSP },
    { RESET, 0x04 },
    { HSIZE8, 0xc8 },
    { VSIZE8, 0x96 },
    { CTRL2, 0x3d },
    { CTRLI, 0x89 },
    { HSIZE, 0x90 },
    { VSIZE, 0x2c },
    { XOFFL, 0x00 },
    { YOFFL, 0x00 },
    { VHYX, 0x88 },
    { TEST, 0x00 },
    { ZMOW, 0xa0 },
    { ZMOH, 0x78 },
    { ZMHH, 0x00 },
    { R_DVP_SP, 0x04 },
    { RESET, 0x00 },
    { 0, 0 }
};

/* JPG 800x600 */
static const uint8_t OV2640_DSP_800x600[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { RESET, 0x04 },
    { HSIZE8, 0xc8 },
    { VSIZE8, 0x96 },
    { CTRL2, 0x35 },
    { CTRLI, 0x89 },
    { HSIZE, 0x90 },
    { VSIZE, 0x2c },
    { XOFFL, 0x00 },
    { YOFFL, 0x00 },
    { VHYX, 0x88 },
    { TEST, 0x00 },
    { ZMOW, 0xc8 },
    { ZMOH, 0x96 },
    { ZMHH, 0x00 },
    { R_DVP_SP, 0x02 },
    { RESET, 0x00 },
    { 0, 0 }
};

/* JPG 1024x768 */
static const uint8_t OV2640_DSP_1024x768[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { RESET, 0x04 },
    { HSIZE8, 0xc8 },
    { VSIZE8, 0x96 },
    { CTRL2, 0x3d },
    { CTRLI, 0x00 },
    { HSIZE, 0x90 },
    { VSIZE, 0x2c },
    { XOFFL, 0x00 },
    { YOFFL, 0x00 },
    { VHYX, 0x88 },
    { TEST, 0x00 },
    { ZMOW, 0x00 },
    { ZMOH, 0xc0 },
    { ZMHH, 0x01 },
    { R_DVP_SP, 0x02 },
    { RESET, 0x00 },
    { 0, 0 }
};

/* JPG 1280x1024 */
static const uint8_t OV2640_DSP_1280x1024[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { RESET, 0x04 },
    { HSIZE8, 0xc8 },
    { VSIZE8, 0x96 },
    { CTRL2, 0x3d },
    { CTRLI, 0x00 },
    { HSIZE, 0x90 },
    { VSIZE, 0x2c },
    { XOFFL, 0x00 },
    { YOFFL, 0x00 },
    { VHYX, 0x88 },
    { TEST, 0x00 },
    { ZMOW, 0x40 },
    { ZMOH, 0xf0 },
    { ZMHH, 0x01 },
    { R_DVP_SP, 0x02 },
    { RESET, 0x00 },
    { 0, 0 }
};

/* JPG 1600x1200 */
static const uint8_t OV2640_DSP_1600x1200[][2] =
{
    { BANK_SEL, BANK_SEL_DSP },
    { RESET, 0x04 },
    { HSIZE8, 0xc8 },
    { VSIZE8, 0x96 },
    { CTRL2, 0x3d },
    { CTRLI, 0x00 },
    { HSIZE, 0x90 },
    { VSIZE, 0x2c },
    { XOFFL, 0x00 },
    { YOFFL, 0x00 },
    { VHYX, 0x88 },
    { TEST, 0x00 },
    { ZMOW, 0x90 },
    { ZMOH, 0x2c },
    { ZMHH, 0x05 },
    { R_DVP_SP, 0x02 },
    { RESET, 0x00 },
    { 0, 0 }
};

#endif
