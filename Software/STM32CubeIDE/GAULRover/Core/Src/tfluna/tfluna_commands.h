/*
 * tfluna_commands.h
 *
 *  Created on: Feb 21, 2026
 *      Author: Etienne
 */

#ifndef SRC_TFLUNA_TFLUNA_COMMANDS_H_
#define SRC_TFLUNA_TFLUNA_COMMANDS_H_

/* -------------------------------------------------------------------------- */
/*                          Commands Data Definitions                          */
/* -------------------------------------------------------------------------- */

typedef enum
{
    TF_LUNA_CMD_SET_FRAME_RATE        = 0x03U,  /* Set output frequency (1–250 Hz) */
    TF_LUNA_CMD_TRIGGER_MEASUREMENT   = 0x04U,  /* Trigger single measurement */
    TF_LUNA_CMD_SET_BAUDRATE          = 0x06U,  /* Set UART baudrate */
    TF_LUNA_CMD_SET_CONTINUOUS_OUTPUT = 0x07U,  /* Enable/Disable continuous output */
    TF_LUNA_CMD_RESTORE_FACTORY       = 0x10U,  /* Restore factory settings */
    TF_LUNA_CMD_SAVE_SETTINGS         = 0x11U,  /* Save current settings to flash */
    TF_LUNA_CMD_SET_I2C_ADDRESS       = 0x0BU,  /* Set I2C address (if in I2C mode) */
    TF_LUNA_CMD_SET_OUTPUT_FORMAT     = 0x05U   /* Change output format (firmware dependent) */

} eTFLunaCommands_t;

/* -------------------------------------------------------------------------- */
/*                          Command Data Definitions                          */
/* -------------------------------------------------------------------------- */

/* ===================== Output Enable (CMD 0x07) =========================== */

#define TF_LUNA_OUTPUT_DISABLE        0x00000000U
#define TF_LUNA_OUTPUT_ENABLE         0x00000001U

/* ===================== Frame Rate (CMD 0x03) ============================== */
/* Valid range: 1 – 250 Hz */

#define TF_LUNA_FRAMERATE_MIN         1U
#define TF_LUNA_FRAMERATE_NORMAL      100U //Default value
#define TF_LUNA_FRAMERATE_MAX         250U

/* ===================== Trigger Measurement (CMD 0x04) ===================== */
/* Must send 1 to trigger */

#define TF_LUNA_TRIGGER_ONCE          0x00000001U

/* ===================== Baud Rates (CMD 0x06) ============================== */

#define TF_LUNA_BAUD_9600             9600U
#define TF_LUNA_BAUD_19200            19200U
#define TF_LUNA_BAUD_38400            38400U
#define TF_LUNA_BAUD_57600            57600U
#define TF_LUNA_BAUD_115200           115200U //Default value
#define TF_LUNA_BAUD_230400           230400U
#define TF_LUNA_BAUD_460800           460800U
#define TF_LUNA_BAUD_921600           921600U

/* ======= Save / Restore Commands (CMD 0x10) (CMD 0x11) (CMD 0x04) ========= */
/* Data must be 0 */

#define TF_LUNA_NO_DATA               0x00000000U

/* ===================== I2C Address (CMD 0x0B) ============================= */
/* Valid 7-bit addresses typically 0x08 – 0x77 */

#define TF_LUNA_I2C_ADDR_MIN          0x08U
#define TF_LUNA_I2C_ADDR_MAX          0x77U

/* ===================== Output Format (CMD 0x05) =========================== */
/* Firmware dependent — typical values */

#define TF_LUNA_FORMAT_STANDARD       0x01U
#define TF_LUNA_FORMAT_PIXHAWK        0x02U



#endif /* SRC_TFLUNA_TFLUNA_COMMANDS_H_ */
