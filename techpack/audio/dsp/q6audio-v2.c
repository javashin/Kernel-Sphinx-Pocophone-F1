/* Copyright (c) 2012-2017, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/slab.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/jiffies.h>
#include <linux/uaccess.h>
#include <linux/atomic.h>
#include <dsp/q6afe-v2.h>
#include <dsp/q6audio-v2.h>

int q6audio_get_port_index(u16 port_id)
{
	switch (port_id) {
	case PRIMARY_I2S_RX: return IDX_PRIMARY_I2S_RX;
	case PRIMARY_I2S_TX: return IDX_PRIMARY_I2S_TX;
	case AFE_PORT_ID_PRIMARY_PCM_RX:
		return IDX_AFE_PORT_ID_PRIMARY_PCM_RX;
	case AFE_PORT_ID_PRIMARY_PCM_TX:
		return IDX_AFE_PORT_ID_PRIMARY_PCM_TX;
	case AFE_PORT_ID_SECONDARY_PCM_RX:
		return IDX_AFE_PORT_ID_SECONDARY_PCM_RX;
	case AFE_PORT_ID_SECONDARY_PCM_TX:
		return IDX_AFE_PORT_ID_SECONDARY_PCM_TX;
	case AFE_PORT_ID_TERTIARY_PCM_RX:
		return IDX_AFE_PORT_ID_TERTIARY_PCM_RX;
	case AFE_PORT_ID_TERTIARY_PCM_TX:
		return IDX_AFE_PORT_ID_TERTIARY_PCM_TX;
	case AFE_PORT_ID_QUATERNARY_PCM_RX:
		return IDX_AFE_PORT_ID_QUATERNARY_PCM_RX;
	case AFE_PORT_ID_QUATERNARY_PCM_TX:
		return IDX_AFE_PORT_ID_QUATERNARY_PCM_TX;
	case AFE_PORT_ID_QUINARY_PCM_RX:
		return IDX_AFE_PORT_ID_QUINARY_PCM_RX;
	case AFE_PORT_ID_QUINARY_PCM_TX:
		return IDX_AFE_PORT_ID_QUINARY_PCM_TX;
	case SECONDARY_I2S_RX: return IDX_SECONDARY_I2S_RX;
	case SECONDARY_I2S_TX: return IDX_SECONDARY_I2S_TX;
	case MI2S_RX: return IDX_MI2S_RX;
	case MI2S_TX: return IDX_MI2S_TX;
	case HDMI_RX: return IDX_HDMI_RX;
	case DISPLAY_PORT_RX: return IDX_DISPLAY_PORT_RX;
	case AFE_PORT_ID_SPDIF_RX: return IDX_SPDIF_RX;
	case RSVD_2: return IDX_RSVD_2;
	case RSVD_3: return IDX_RSVD_3;
	case DIGI_MIC_TX: return IDX_DIGI_MIC_TX;
	case VOICE_RECORD_RX: return IDX_VOICE_RECORD_RX;
	case VOICE_RECORD_TX: return IDX_VOICE_RECORD_TX;
	case VOICE_PLAYBACK_TX: return IDX_VOICE_PLAYBACK_TX;
	case VOICE2_PLAYBACK_TX: return IDX_VOICE2_PLAYBACK_TX;
	case SLIMBUS_0_RX: return IDX_SLIMBUS_0_RX;
	case SLIMBUS_0_TX: return IDX_SLIMBUS_0_TX;
	case SLIMBUS_1_RX: return IDX_SLIMBUS_1_RX;
	case SLIMBUS_1_TX: return IDX_SLIMBUS_1_TX;
	case SLIMBUS_2_RX: return IDX_SLIMBUS_2_RX;
	case SLIMBUS_2_TX: return IDX_SLIMBUS_2_TX;
	case SLIMBUS_3_RX: return IDX_SLIMBUS_3_RX;
	case SLIMBUS_3_TX: return IDX_SLIMBUS_3_TX;
	case SLIMBUS_4_RX: return IDX_SLIMBUS_4_RX;
	case SLIMBUS_4_TX: return IDX_SLIMBUS_4_TX;
	case SLIMBUS_5_RX: return IDX_SLIMBUS_5_RX;
	case SLIMBUS_5_TX: return IDX_SLIMBUS_5_TX;
	case SLIMBUS_6_RX: return IDX_SLIMBUS_6_RX;
	case SLIMBUS_6_TX: return IDX_SLIMBUS_6_TX;
	case SLIMBUS_7_RX: return IDX_SLIMBUS_7_RX;
	case SLIMBUS_7_TX: return IDX_SLIMBUS_7_TX;
	case SLIMBUS_8_RX: return IDX_SLIMBUS_8_RX;
	case SLIMBUS_8_TX: return IDX_SLIMBUS_8_TX;
	case INT_BT_SCO_RX: return IDX_INT_BT_SCO_RX;
	case INT_BT_SCO_TX: return IDX_INT_BT_SCO_TX;
	case INT_BT_A2DP_RX: return IDX_INT_BT_A2DP_RX;
	case INT_FM_RX: return IDX_INT_FM_RX;
	case INT_FM_TX: return IDX_INT_FM_TX;
	case RT_PROXY_PORT_001_RX: return IDX_RT_PROXY_PORT_001_RX;
	case RT_PROXY_PORT_001_TX: return IDX_RT_PROXY_PORT_001_TX;
	case AFE_PORT_ID_PRIMARY_MI2S_RX:
		return IDX_AFE_PORT_ID_PRIMARY_MI2S_RX;
	case AFE_PORT_ID_PRIMARY_MI2S_TX:
		return IDX_AFE_PORT_ID_PRIMARY_MI2S_TX;
	case AFE_PORT_ID_QUATERNARY_MI2S_RX:
		return IDX_AFE_PORT_ID_QUATERNARY_MI2S_RX;
	case AFE_PORT_ID_QUATERNARY_MI2S_TX:
		return IDX_AFE_PORT_ID_QUATERNARY_MI2S_TX;
	case AFE_PORT_ID_SECONDARY_MI2S_RX:
		return IDX_AFE_PORT_ID_SECONDARY_MI2S_RX;
	case AFE_PORT_ID_SECONDARY_MI2S_TX:
		return IDX_AFE_PORT_ID_SECONDARY_MI2S_TX;
	case AFE_PORT_ID_TERTIARY_MI2S_RX:
		return IDX_AFE_PORT_ID_TERTIARY_MI2S_RX;
	case AFE_PORT_ID_TERTIARY_MI2S_TX:
		return IDX_AFE_PORT_ID_TERTIARY_MI2S_TX;
	case AFE_PORT_ID_QUINARY_MI2S_RX:
		return IDX_AFE_PORT_ID_QUINARY_MI2S_RX;
	case AFE_PORT_ID_QUINARY_MI2S_TX:
		return IDX_AFE_PORT_ID_QUINARY_MI2S_TX;
	case AUDIO_PORT_ID_I2S_RX:
		return IDX_AUDIO_PORT_ID_I2S_RX;
	case AFE_PORT_ID_SECONDARY_MI2S_RX_SD1:
		return IDX_AFE_PORT_ID_SECONDARY_MI2S_RX_SD1;
	case AFE_PORT_ID_PRIMARY_TDM_RX:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_RX_0;
	case AFE_PORT_ID_PRIMARY_TDM_TX:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_TX_0;
	case AFE_PORT_ID_PRIMARY_TDM_RX_1:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_RX_1;
	case AFE_PORT_ID_PRIMARY_TDM_TX_1:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_TX_1;
	case AFE_PORT_ID_PRIMARY_TDM_RX_2:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_RX_2;
	case AFE_PORT_ID_PRIMARY_TDM_TX_2:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_TX_2;
	case AFE_PORT_ID_PRIMARY_TDM_RX_3:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_RX_3;
	case AFE_PORT_ID_PRIMARY_TDM_TX_3:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_TX_3;
	case AFE_PORT_ID_PRIMARY_TDM_RX_4:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_RX_4;
	case AFE_PORT_ID_PRIMARY_TDM_TX_4:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_TX_4;
	case AFE_PORT_ID_PRIMARY_TDM_RX_5:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_RX_5;
	case AFE_PORT_ID_PRIMARY_TDM_TX_5:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_TX_5;
	case AFE_PORT_ID_PRIMARY_TDM_RX_6:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_RX_6;
	case AFE_PORT_ID_PRIMARY_TDM_TX_6:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_TX_6;
	case AFE_PORT_ID_PRIMARY_TDM_RX_7:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_RX_7;
	case AFE_PORT_ID_PRIMARY_TDM_TX_7:
		return IDX_AFE_PORT_ID_PRIMARY_TDM_TX_7;
	case AFE_PORT_ID_SECONDARY_TDM_RX:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_RX_0;
	case AFE_PORT_ID_SECONDARY_TDM_TX:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_TX_0;
	case AFE_PORT_ID_SECONDARY_TDM_RX_1:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_RX_1;
	case AFE_PORT_ID_SECONDARY_TDM_TX_1:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_TX_1;
	case AFE_PORT_ID_SECONDARY_TDM_RX_2:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_RX_2;
	case AFE_PORT_ID_SECONDARY_TDM_TX_2:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_TX_2;
	case AFE_PORT_ID_SECONDARY_TDM_RX_3:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_RX_3;
	case AFE_PORT_ID_SECONDARY_TDM_TX_3:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_TX_3;
	case AFE_PORT_ID_SECONDARY_TDM_RX_4:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_RX_4;
	case AFE_PORT_ID_SECONDARY_TDM_TX_4:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_TX_4;
	case AFE_PORT_ID_SECONDARY_TDM_RX_5:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_RX_5;
	case AFE_PORT_ID_SECONDARY_TDM_TX_5:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_TX_5;
	case AFE_PORT_ID_SECONDARY_TDM_RX_6:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_RX_6;
	case AFE_PORT_ID_SECONDARY_TDM_TX_6:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_TX_6;
	case AFE_PORT_ID_SECONDARY_TDM_RX_7:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_RX_7;
	case AFE_PORT_ID_SECONDARY_TDM_TX_7:
		return IDX_AFE_PORT_ID_SECONDARY_TDM_TX_7;
	case AFE_PORT_ID_TERTIARY_TDM_RX:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_RX_0;
	case AFE_PORT_ID_TERTIARY_TDM_TX:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_TX_0;
	case AFE_PORT_ID_TERTIARY_TDM_RX_1:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_RX_1;
	case AFE_PORT_ID_TERTIARY_TDM_TX_1:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_TX_1;
	case AFE_PORT_ID_TERTIARY_TDM_RX_2:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_RX_2;
	case AFE_PORT_ID_TERTIARY_TDM_TX_2:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_TX_2;
	case AFE_PORT_ID_TERTIARY_TDM_RX_3:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_RX_3;
	case AFE_PORT_ID_TERTIARY_TDM_TX_3:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_TX_3;
	case AFE_PORT_ID_TERTIARY_TDM_RX_4:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_RX_4;
	case AFE_PORT_ID_TERTIARY_TDM_TX_4:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_TX_4;
	case AFE_PORT_ID_TERTIARY_TDM_RX_5:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_RX_5;
	case AFE_PORT_ID_TERTIARY_TDM_TX_5:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_TX_5;
	case AFE_PORT_ID_TERTIARY_TDM_RX_6:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_RX_6;
	case AFE_PORT_ID_TERTIARY_TDM_TX_6:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_TX_6;
	case AFE_PORT_ID_TERTIARY_TDM_RX_7:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_RX_7;
	case AFE_PORT_ID_TERTIARY_TDM_TX_7:
		return IDX_AFE_PORT_ID_TERTIARY_TDM_TX_7;
	case AFE_PORT_ID_QUATERNARY_TDM_RX:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_0;
	case AFE_PORT_ID_QUATERNARY_TDM_TX:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_0;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_1:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_1;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_1:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_1;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_2:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_2;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_2:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_2;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_3:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_3;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_3:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_3;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_4:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_4;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_4:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_4;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_5:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_5;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_5:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_5;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_6:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_6;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_6:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_6;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_7:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_RX_7;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_7:
		return IDX_AFE_PORT_ID_QUATERNARY_TDM_TX_7;
	case AFE_PORT_ID_QUINARY_TDM_RX:
		return IDX_AFE_PORT_ID_QUINARY_TDM_RX_0;
	case AFE_PORT_ID_QUINARY_TDM_TX:
		return IDX_AFE_PORT_ID_QUINARY_TDM_TX_0;
	case AFE_PORT_ID_QUINARY_TDM_RX_1:
		return IDX_AFE_PORT_ID_QUINARY_TDM_RX_1;
	case AFE_PORT_ID_QUINARY_TDM_TX_1:
		return IDX_AFE_PORT_ID_QUINARY_TDM_TX_1;
	case AFE_PORT_ID_QUINARY_TDM_RX_2:
		return IDX_AFE_PORT_ID_QUINARY_TDM_RX_2;
	case AFE_PORT_ID_QUINARY_TDM_TX_2:
		return IDX_AFE_PORT_ID_QUINARY_TDM_TX_2;
	case AFE_PORT_ID_QUINARY_TDM_RX_3:
		return IDX_AFE_PORT_ID_QUINARY_TDM_RX_3;
	case AFE_PORT_ID_QUINARY_TDM_TX_3:
		return IDX_AFE_PORT_ID_QUINARY_TDM_TX_3;
	case AFE_PORT_ID_QUINARY_TDM_RX_4:
		return IDX_AFE_PORT_ID_QUINARY_TDM_RX_4;
	case AFE_PORT_ID_QUINARY_TDM_TX_4:
		return IDX_AFE_PORT_ID_QUINARY_TDM_TX_4;
	case AFE_PORT_ID_QUINARY_TDM_RX_5:
		return IDX_AFE_PORT_ID_QUINARY_TDM_RX_5;
	case AFE_PORT_ID_QUINARY_TDM_TX_5:
		return IDX_AFE_PORT_ID_QUINARY_TDM_TX_5;
	case AFE_PORT_ID_QUINARY_TDM_RX_6:
		return IDX_AFE_PORT_ID_QUINARY_TDM_RX_6;
	case AFE_PORT_ID_QUINARY_TDM_TX_6:
		return IDX_AFE_PORT_ID_QUINARY_TDM_TX_6;
	case AFE_PORT_ID_QUINARY_TDM_RX_7:
		return IDX_AFE_PORT_ID_QUINARY_TDM_RX_7;
	case AFE_PORT_ID_QUINARY_TDM_TX_7:
		return IDX_AFE_PORT_ID_QUINARY_TDM_TX_7;
	case AFE_PORT_ID_SENARY_MI2S_TX:
		return IDX_AFE_PORT_ID_SENARY_MI2S_TX;
	case AFE_PORT_ID_USB_RX:
		return IDX_AFE_PORT_ID_USB_RX;
	case AFE_PORT_ID_USB_TX:
		return IDX_AFE_PORT_ID_USB_TX;
	case AFE_PORT_ID_INT0_MI2S_RX:
		return IDX_AFE_PORT_ID_INT0_MI2S_RX;
	case AFE_PORT_ID_INT0_MI2S_TX:
		return IDX_AFE_PORT_ID_INT0_MI2S_TX;
	case AFE_PORT_ID_INT1_MI2S_RX:
		return IDX_AFE_PORT_ID_INT1_MI2S_RX;
	case AFE_PORT_ID_INT1_MI2S_TX:
		return IDX_AFE_PORT_ID_INT1_MI2S_TX;
	case AFE_PORT_ID_INT2_MI2S_RX:
		return IDX_AFE_PORT_ID_INT2_MI2S_RX;
	case AFE_PORT_ID_INT2_MI2S_TX:
		return IDX_AFE_PORT_ID_INT2_MI2S_TX;
	case AFE_PORT_ID_INT3_MI2S_RX:
		return IDX_AFE_PORT_ID_INT3_MI2S_RX;
	case AFE_PORT_ID_INT3_MI2S_TX:
		return IDX_AFE_PORT_ID_INT3_MI2S_TX;
	case AFE_PORT_ID_INT4_MI2S_RX:
		return IDX_AFE_PORT_ID_INT4_MI2S_RX;
	case AFE_PORT_ID_INT4_MI2S_TX:
		return IDX_AFE_PORT_ID_INT4_MI2S_TX;
	case AFE_PORT_ID_INT5_MI2S_RX:
		return IDX_AFE_PORT_ID_INT5_MI2S_RX;
	case AFE_PORT_ID_INT5_MI2S_TX:
		return IDX_AFE_PORT_ID_INT5_MI2S_TX;
	case AFE_PORT_ID_INT6_MI2S_RX:
		return IDX_AFE_PORT_ID_INT6_MI2S_RX;
	case AFE_PORT_ID_INT6_MI2S_TX:
		return IDX_AFE_PORT_ID_INT6_MI2S_TX;
	case AFE_PORT_ID_PSEUDOPORT_01:
		return IDX_AFE_PORT_ID_PSEUDOPORT_01;
	default: return -EINVAL;
	}
}

int q6audio_get_port_id(u16 port_id)
{
	switch (port_id) {
	case PRIMARY_I2S_RX: return PRIMARY_I2S_RX;
	case PRIMARY_I2S_TX: return PRIMARY_I2S_TX;
	case AFE_PORT_ID_PRIMARY_PCM_RX:
			return AFE_PORT_ID_PRIMARY_PCM_RX;
	case AFE_PORT_ID_PRIMARY_PCM_TX:
			return AFE_PORT_ID_PRIMARY_PCM_TX;
	case AFE_PORT_ID_SECONDARY_PCM_RX:
			return AFE_PORT_ID_SECONDARY_PCM_RX;
	case AFE_PORT_ID_SECONDARY_PCM_TX:
			return AFE_PORT_ID_SECONDARY_PCM_TX;
	case AFE_PORT_ID_TERTIARY_PCM_RX:
			return AFE_PORT_ID_TERTIARY_PCM_RX;
	case AFE_PORT_ID_TERTIARY_PCM_TX:
			return AFE_PORT_ID_TERTIARY_PCM_TX;
	case AFE_PORT_ID_QUATERNARY_PCM_RX:
			return AFE_PORT_ID_QUATERNARY_PCM_RX;
	case AFE_PORT_ID_QUATERNARY_PCM_TX:
			return AFE_PORT_ID_QUATERNARY_PCM_TX;
	case AFE_PORT_ID_QUINARY_PCM_RX:
			return AFE_PORT_ID_QUINARY_PCM_RX;
	case AFE_PORT_ID_QUINARY_PCM_TX:
			return AFE_PORT_ID_QUINARY_PCM_TX;
	case SECONDARY_I2S_RX: return AFE_PORT_ID_SECONDARY_MI2S_RX;
	case SECONDARY_I2S_TX: return AFE_PORT_ID_SECONDARY_MI2S_TX;
	case MI2S_RX: return AFE_PORT_ID_PRIMARY_MI2S_RX;
	case MI2S_TX: return AFE_PORT_ID_PRIMARY_MI2S_TX;
	case HDMI_RX: return AFE_PORT_ID_MULTICHAN_HDMI_RX;
	case DISPLAY_PORT_RX:
			return AFE_PORT_ID_HDMI_OVER_DP_RX;
	case AFE_PORT_ID_SPDIF_RX: return AFE_PORT_ID_SPDIF_RX;
	case RSVD_2: return IDX_RSVD_2;
	case RSVD_3: return IDX_RSVD_3;
	case DIGI_MIC_TX: return AFE_PORT_ID_DIGITAL_MIC_TX;
	case VOICE_RECORD_RX: return AFE_PORT_ID_VOICE_RECORD_RX;
	case VOICE_RECORD_TX: return AFE_PORT_ID_VOICE_RECORD_TX;
	case VOICE_PLAYBACK_TX: return AFE_PORT_ID_VOICE_PLAYBACK_TX;
	case VOICE2_PLAYBACK_TX: return AFE_PORT_ID_VOICE2_PLAYBACK_TX;
	case SLIMBUS_0_RX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_0_RX;
	case SLIMBUS_0_TX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_0_TX;
	case SLIMBUS_1_RX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_1_RX;
	case SLIMBUS_1_TX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_1_TX;
	case SLIMBUS_2_RX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_2_RX;
	case SLIMBUS_2_TX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_2_TX;
	case SLIMBUS_3_RX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_3_RX;
	case SLIMBUS_3_TX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_3_TX;
	case SLIMBUS_4_RX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_4_RX;
	case SLIMBUS_4_TX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_4_TX;
	case SLIMBUS_5_RX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_5_RX;
	case SLIMBUS_5_TX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_5_TX;
	case SLIMBUS_6_RX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_6_RX;
	case SLIMBUS_6_TX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_6_TX;
	case SLIMBUS_7_RX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_7_RX;
	case SLIMBUS_7_TX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_7_TX;
	case SLIMBUS_8_RX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_8_RX;
	case SLIMBUS_8_TX: return AFE_PORT_ID_SLIMBUS_MULTI_CHAN_8_TX;
	case INT_BT_SCO_RX: return AFE_PORT_ID_INTERNAL_BT_SCO_RX;
	case INT_BT_SCO_TX: return AFE_PORT_ID_INTERNAL_BT_SCO_TX;
	case INT_BT_A2DP_RX: return AFE_PORT_ID_INTERNAL_BT_A2DP_RX;
	case INT_FM_RX: return AFE_PORT_ID_INTERNAL_FM_RX;
	case INT_FM_TX: return AFE_PORT_ID_INTERNAL_FM_TX;
	case RT_PROXY_PORT_001_RX: return AFE_PORT_ID_RT_PROXY_PORT_001_RX;
	case RT_PROXY_PORT_001_TX: return AFE_PORT_ID_RT_PROXY_PORT_001_TX;
	case AFE_PORT_ID_PRIMARY_MI2S_RX:
			return AFE_PORT_ID_PRIMARY_MI2S_RX;
	case AFE_PORT_ID_PRIMARY_MI2S_TX:
			return AFE_PORT_ID_PRIMARY_MI2S_TX;
	case AFE_PORT_ID_QUATERNARY_MI2S_RX:
			return AFE_PORT_ID_QUATERNARY_MI2S_RX;
	case AFE_PORT_ID_QUATERNARY_MI2S_TX:
			return AFE_PORT_ID_QUATERNARY_MI2S_TX;
	case AFE_PORT_ID_SECONDARY_MI2S_RX:
			return AFE_PORT_ID_SECONDARY_MI2S_RX;
	case AFE_PORT_ID_SECONDARY_MI2S_TX:
			return AFE_PORT_ID_SECONDARY_MI2S_TX;
	case AFE_PORT_ID_TERTIARY_MI2S_RX:
			return AFE_PORT_ID_TERTIARY_MI2S_RX;
	case AFE_PORT_ID_TERTIARY_MI2S_TX:
			return AFE_PORT_ID_TERTIARY_MI2S_TX;
	case AFE_PORT_ID_QUINARY_MI2S_RX:
			return AFE_PORT_ID_QUINARY_MI2S_RX;
	case AFE_PORT_ID_QUINARY_MI2S_TX:
			return AFE_PORT_ID_QUINARY_MI2S_TX;
	case AUDIO_PORT_ID_I2S_RX:
			return AUDIO_PORT_ID_I2S_RX;
	case AFE_PORT_ID_SECONDARY_MI2S_RX_SD1:
			return AFE_PORT_ID_SECONDARY_MI2S_RX_SD1;
	case AFE_PORT_ID_PRIMARY_TDM_RX:
		return AFE_PORT_ID_PRIMARY_TDM_RX;
	case AFE_PORT_ID_PRIMARY_TDM_TX:
		return AFE_PORT_ID_PRIMARY_TDM_TX;
	case AFE_PORT_ID_PRIMARY_TDM_RX_1:
		return AFE_PORT_ID_PRIMARY_TDM_RX_1;
	case AFE_PORT_ID_PRIMARY_TDM_TX_1:
		return AFE_PORT_ID_PRIMARY_TDM_TX_1;
	case AFE_PORT_ID_PRIMARY_TDM_RX_2:
		return AFE_PORT_ID_PRIMARY_TDM_RX_2;
	case AFE_PORT_ID_PRIMARY_TDM_TX_2:
		return AFE_PORT_ID_PRIMARY_TDM_TX_2;
	case AFE_PORT_ID_PRIMARY_TDM_RX_3:
		return AFE_PORT_ID_PRIMARY_TDM_RX_3;
	case AFE_PORT_ID_PRIMARY_TDM_TX_3:
		return AFE_PORT_ID_PRIMARY_TDM_TX_3;
	case AFE_PORT_ID_PRIMARY_TDM_RX_4:
		return AFE_PORT_ID_PRIMARY_TDM_RX_4;
	case AFE_PORT_ID_PRIMARY_TDM_TX_4:
		return AFE_PORT_ID_PRIMARY_TDM_TX_4;
	case AFE_PORT_ID_PRIMARY_TDM_RX_5:
		return AFE_PORT_ID_PRIMARY_TDM_RX_5;
	case AFE_PORT_ID_PRIMARY_TDM_TX_5:
		return AFE_PORT_ID_PRIMARY_TDM_TX_5;
	case AFE_PORT_ID_PRIMARY_TDM_RX_6:
		return AFE_PORT_ID_PRIMARY_TDM_RX_6;
	case AFE_PORT_ID_PRIMARY_TDM_TX_6:
		return AFE_PORT_ID_PRIMARY_TDM_TX_6;
	case AFE_PORT_ID_PRIMARY_TDM_RX_7:
		return AFE_PORT_ID_PRIMARY_TDM_RX_7;
	case AFE_PORT_ID_PRIMARY_TDM_TX_7:
		return AFE_PORT_ID_PRIMARY_TDM_TX_7;
	case AFE_PORT_ID_SECONDARY_TDM_RX:
		return AFE_PORT_ID_SECONDARY_TDM_RX;
	case AFE_PORT_ID_SECONDARY_TDM_TX:
		return AFE_PORT_ID_SECONDARY_TDM_TX;
	case AFE_PORT_ID_SECONDARY_TDM_RX_1:
		return AFE_PORT_ID_SECONDARY_TDM_RX_1;
	case AFE_PORT_ID_SECONDARY_TDM_TX_1:
		return AFE_PORT_ID_SECONDARY_TDM_TX_1;
	case AFE_PORT_ID_SECONDARY_TDM_RX_2:
		return AFE_PORT_ID_SECONDARY_TDM_RX_2;
	case AFE_PORT_ID_SECONDARY_TDM_TX_2:
		return AFE_PORT_ID_SECONDARY_TDM_TX_2;
	case AFE_PORT_ID_SECONDARY_TDM_RX_3:
		return AFE_PORT_ID_SECONDARY_TDM_RX_3;
	case AFE_PORT_ID_SECONDARY_TDM_TX_3:
		return AFE_PORT_ID_SECONDARY_TDM_TX_3;
	case AFE_PORT_ID_SECONDARY_TDM_RX_4:
		return AFE_PORT_ID_SECONDARY_TDM_RX_4;
	case AFE_PORT_ID_SECONDARY_TDM_TX_4:
		return AFE_PORT_ID_SECONDARY_TDM_TX_4;
	case AFE_PORT_ID_SECONDARY_TDM_RX_5:
		return AFE_PORT_ID_SECONDARY_TDM_RX_5;
	case AFE_PORT_ID_SECONDARY_TDM_TX_5:
		return AFE_PORT_ID_SECONDARY_TDM_TX_5;
	case AFE_PORT_ID_SECONDARY_TDM_RX_6:
		return AFE_PORT_ID_SECONDARY_TDM_RX_6;
	case AFE_PORT_ID_SECONDARY_TDM_TX_6:
		return AFE_PORT_ID_SECONDARY_TDM_TX_6;
	case AFE_PORT_ID_SECONDARY_TDM_RX_7:
		return AFE_PORT_ID_SECONDARY_TDM_RX_7;
	case AFE_PORT_ID_SECONDARY_TDM_TX_7:
		return AFE_PORT_ID_SECONDARY_TDM_TX_7;
	case AFE_PORT_ID_TERTIARY_TDM_RX:
		return AFE_PORT_ID_TERTIARY_TDM_RX;
	case AFE_PORT_ID_TERTIARY_TDM_TX:
		return AFE_PORT_ID_TERTIARY_TDM_TX;
	case AFE_PORT_ID_TERTIARY_TDM_RX_1:
		return AFE_PORT_ID_TERTIARY_TDM_RX_1;
	case AFE_PORT_ID_TERTIARY_TDM_TX_1:
		return AFE_PORT_ID_TERTIARY_TDM_TX_1;
	case AFE_PORT_ID_TERTIARY_TDM_RX_2:
		return AFE_PORT_ID_TERTIARY_TDM_RX_2;
	case AFE_PORT_ID_TERTIARY_TDM_TX_2:
		return AFE_PORT_ID_TERTIARY_TDM_TX_2;
	case AFE_PORT_ID_TERTIARY_TDM_RX_3:
		return AFE_PORT_ID_TERTIARY_TDM_RX_3;
	case AFE_PORT_ID_TERTIARY_TDM_TX_3:
		return AFE_PORT_ID_TERTIARY_TDM_TX_3;
	case AFE_PORT_ID_TERTIARY_TDM_RX_4:
		return AFE_PORT_ID_TERTIARY_TDM_RX_4;
	case AFE_PORT_ID_TERTIARY_TDM_TX_4:
		return AFE_PORT_ID_TERTIARY_TDM_TX_4;
	case AFE_PORT_ID_TERTIARY_TDM_RX_5:
		return AFE_PORT_ID_TERTIARY_TDM_RX_5;
	case AFE_PORT_ID_TERTIARY_TDM_TX_5:
		return AFE_PORT_ID_TERTIARY_TDM_TX_5;
	case AFE_PORT_ID_TERTIARY_TDM_RX_6:
		return AFE_PORT_ID_TERTIARY_TDM_RX_6;
	case AFE_PORT_ID_TERTIARY_TDM_TX_6:
		return AFE_PORT_ID_TERTIARY_TDM_TX_6;
	case AFE_PORT_ID_TERTIARY_TDM_RX_7:
		return AFE_PORT_ID_TERTIARY_TDM_RX_7;
	case AFE_PORT_ID_TERTIARY_TDM_TX_7:
		return AFE_PORT_ID_TERTIARY_TDM_TX_7;
	case AFE_PORT_ID_QUATERNARY_TDM_RX:
		return AFE_PORT_ID_QUATERNARY_TDM_RX;
	case AFE_PORT_ID_QUATERNARY_TDM_TX:
		return AFE_PORT_ID_QUATERNARY_TDM_TX;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_1:
		return AFE_PORT_ID_QUATERNARY_TDM_RX_1;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_1:
		return AFE_PORT_ID_QUATERNARY_TDM_TX_1;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_2:
		return AFE_PORT_ID_QUATERNARY_TDM_RX_2;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_2:
		return AFE_PORT_ID_QUATERNARY_TDM_TX_2;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_3:
		return AFE_PORT_ID_QUATERNARY_TDM_RX_3;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_3:
		return AFE_PORT_ID_QUATERNARY_TDM_TX_3;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_4:
		return AFE_PORT_ID_QUATERNARY_TDM_RX_4;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_4:
		return AFE_PORT_ID_QUATERNARY_TDM_TX_4;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_5:
		return AFE_PORT_ID_QUATERNARY_TDM_RX_5;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_5:
		return AFE_PORT_ID_QUATERNARY_TDM_TX_5;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_6:
		return AFE_PORT_ID_QUATERNARY_TDM_RX_6;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_6:
		return AFE_PORT_ID_QUATERNARY_TDM_TX_6;
	case AFE_PORT_ID_QUATERNARY_TDM_RX_7:
		return AFE_PORT_ID_QUATERNARY_TDM_RX_7;
	case AFE_PORT_ID_QUATERNARY_TDM_TX_7:
		return AFE_PORT_ID_QUATERNARY_TDM_TX_7;
	case AFE_PORT_ID_QUINARY_TDM_RX:
		return AFE_PORT_ID_QUINARY_TDM_RX;
	case AFE_PORT_ID_QUINARY_TDM_TX:
		return AFE_PORT_ID_QUINARY_TDM_TX;
	case AFE_PORT_ID_QUINARY_TDM_RX_1:
		return AFE_PORT_ID_QUINARY_TDM_RX_1;
	case AFE_PORT_ID_QUINARY_TDM_TX_1:
		return AFE_PORT_ID_QUINARY_TDM_TX_1;
	case AFE_PORT_ID_QUINARY_TDM_RX_2:
		return AFE_PORT_ID_QUINARY_TDM_RX_2;
	case AFE_PORT_ID_QUINARY_TDM_TX_2:
		return AFE_PORT_ID_QUINARY_TDM_TX_2;
	case AFE_PORT_ID_QUINARY_TDM_RX_3:
		return AFE_PORT_ID_QUINARY_TDM_RX_3;
	case AFE_PORT_ID_QUINARY_TDM_TX_3:
		return AFE_PORT_ID_QUINARY_TDM_TX_3;
	case AFE_PORT_ID_QUINARY_TDM_RX_4:
		return AFE_PORT_ID_QUINARY_TDM_RX_4;
	case AFE_PORT_ID_QUINARY_TDM_TX_4:
		return AFE_PORT_ID_QUINARY_TDM_TX_4;
	case AFE_PORT_ID_QUINARY_TDM_RX_5:
		return AFE_PORT_ID_QUINARY_TDM_RX_5;
	case AFE_PORT_ID_QUINARY_TDM_TX_5:
		return AFE_PORT_ID_QUINARY_TDM_TX_5;
	case AFE_PORT_ID_QUINARY_TDM_RX_6:
		return AFE_PORT_ID_QUINARY_TDM_RX_6;
	case AFE_PORT_ID_QUINARY_TDM_TX_6:
		return AFE_PORT_ID_QUINARY_TDM_TX_6;
	case AFE_PORT_ID_QUINARY_TDM_RX_7:
		return AFE_PORT_ID_QUINARY_TDM_RX_7;
	case AFE_PORT_ID_QUINARY_TDM_TX_7:
		return AFE_PORT_ID_QUINARY_TDM_TX_7;
	case AFE_PORT_ID_SENARY_MI2S_TX:
		return AFE_PORT_ID_SENARY_MI2S_TX;
	case AFE_PORT_ID_USB_RX:
		return AFE_PORT_ID_USB_RX;
	case AFE_PORT_ID_USB_TX:
		return AFE_PORT_ID_USB_TX;
	case AFE_PORT_ID_INT0_MI2S_RX:
		return AFE_PORT_ID_INT0_MI2S_RX;
	case AFE_PORT_ID_INT0_MI2S_TX:
		return AFE_PORT_ID_INT0_MI2S_TX;
	case AFE_PORT_ID_INT1_MI2S_RX:
		return AFE_PORT_ID_INT1_MI2S_RX;
	case AFE_PORT_ID_INT1_MI2S_TX:
		return AFE_PORT_ID_INT1_MI2S_TX;
	case AFE_PORT_ID_INT2_MI2S_RX:
		return AFE_PORT_ID_INT2_MI2S_RX;
	case AFE_PORT_ID_INT2_MI2S_TX:
		return AFE_PORT_ID_INT2_MI2S_TX;
	case AFE_PORT_ID_INT3_MI2S_RX:
		return AFE_PORT_ID_INT3_MI2S_RX;
	case AFE_PORT_ID_INT3_MI2S_TX:
		return AFE_PORT_ID_INT3_MI2S_TX;
	case AFE_PORT_ID_INT4_MI2S_RX:
		return AFE_PORT_ID_INT4_MI2S_RX;
	case AFE_PORT_ID_INT4_MI2S_TX:
		return AFE_PORT_ID_INT4_MI2S_TX;
	case AFE_PORT_ID_INT5_MI2S_RX:
		return AFE_PORT_ID_INT5_MI2S_RX;
	case AFE_PORT_ID_INT5_MI2S_TX:
		return AFE_PORT_ID_INT5_MI2S_TX;
	case AFE_PORT_ID_INT6_MI2S_RX:
		return AFE_PORT_ID_INT6_MI2S_RX;
	case AFE_PORT_ID_INT6_MI2S_TX:
		return AFE_PORT_ID_INT6_MI2S_TX;
	default:
		pr_warn("%s: Invalid port_id %d\n", __func__, port_id);
		return -EINVAL;
	}
}
int q6audio_convert_virtual_to_portid(u16 port_id)
{
	int ret;

	/* if port_id is virtual, convert to physical..
	 * if port_id is already physical, return physical
	 */
	if (q6audio_validate_port(port_id) < 0) {
		if (port_id == RT_PROXY_DAI_001_RX ||
			port_id == RT_PROXY_DAI_001_TX ||
			port_id == RT_PROXY_DAI_002_RX ||
			port_id == RT_PROXY_DAI_002_TX)
			ret = VIRTUAL_ID_TO_PORTID(port_id);
		else
			ret = -EINVAL;
	} else
		ret = port_id;

	return ret;
}

int q6audio_is_digital_pcm_interface(u16 port_id)
{
	int ret = 0;

	switch (port_id) {
	case PRIMARY_I2S_RX:
	case PRIMARY_I2S_TX:
	case AFE_PORT_ID_PRIMARY_PCM_RX:
	case AFE_PORT_ID_PRIMARY_PCM_TX:
	case AFE_PORT_ID_SECONDARY_PCM_RX:
	case AFE_PORT_ID_SECONDARY_PCM_TX:
	case AFE_PORT_ID_TERTIARY_PCM_RX:
	case AFE_PORT_ID_TERTIARY_PCM_TX:
	case AFE_PORT_ID_QUATERNARY_PCM_RX:
	case AFE_PORT_ID_QUATERNARY_PCM_TX:
	case AFE_PORT_ID_QUINARY_PCM_RX:
	case AFE_PORT_ID_QUINARY_PCM_TX:
	case SECONDARY_I2S_RX:
	case SECONDARY_I2S_TX:
	case MI2S_RX:
	case MI2S_TX:
	case AFE_PORT_ID_TERTIARY_MI2S_TX:
	case AFE_PORT_ID_TERTIARY_MI2S_RX:
	case AFE_PORT_ID_QUINARY_MI2S_TX:
	case AFE_PORT_ID_QUINARY_MI2S_RX:
	case AFE_PORT_ID_QUATERNARY_MI2S_RX:
	case AFE_PORT_ID_QUATERNARY_MI2S_TX:
	case AFE_PORT_ID_PRIMARY_MI2S_RX:
	case AFE_PORT_ID_PRIMARY_MI2S_TX:
	case AFE_PORT_ID_SECONDARY_MI2S_RX:
	case AFE_PORT_ID_SECONDARY_MI2S_TX:
	case AUDIO_PORT_ID_I2S_RX:
	case AFE_PORT_ID_SECONDARY_MI2S_RX_SD1:
	case AFE_PORT_ID_PRIMARY_TDM_RX:
	case AFE_PORT_ID_PRIMARY_TDM_TX:
	case AFE_PORT_ID_PRIMARY_TDM_RX_1:
	case AFE_PORT_ID_PRIMARY_TDM_TX_1:
	case AFE_PORT_ID_PRIMARY_TDM_RX_2:
	case AFE_PORT_ID_PRIMARY_TDM_TX_2:
	case AFE_PORT_ID_PRIMARY_TDM_RX_3:
	case AFE_PORT_ID_PRIMARY_TDM_TX_3:
	case AFE_PORT_ID_PRIMARY_TDM_RX_4:
	case AFE_PORT_ID_PRIMARY_TDM_TX_4:
	case AFE_PORT_ID_PRIMARY_TDM_RX_5:
	case AFE_PORT_ID_PRIMARY_TDM_TX_5:
	case AFE_PORT_ID_PRIMARY_TDM_RX_6:
	case AFE_PORT_ID_PRIMARY_TDM_TX_6:
	case AFE_PORT_ID_PRIMARY_TDM_RX_7:
	case AFE_PORT_ID_PRIMARY_TDM_TX_7:
	case AFE_PORT_ID_SECONDARY_TDM_RX:
	case AFE_PORT_ID_SECONDARY_TDM_TX:
	case AFE_PORT_ID_SECONDARY_TDM_RX_1:
	case AFE_PORT_ID_SECONDARY_TDM_TX_1:
	case AFE_PORT_ID_SECONDARY_TDM_RX_2:
	case AFE_PORT_ID_SECONDARY_TDM_TX_2:
	case AFE_PORT_ID_SECONDARY_TDM_RX_3:
	case AFE_PORT_ID_SECONDARY_TDM_TX_3:
	case AFE_PORT_ID_SECONDARY_TDM_RX_4:
	case AFE_PORT_ID_SECONDARY_TDM_TX_4:
	case AFE_PORT_ID_SECONDARY_TDM_RX_5:
	case AFE_PORT_ID_SECONDARY_TDM_TX_5:
	case AFE_PORT_ID_SECONDARY_TDM_RX_6:
	case AFE_PORT_ID_SECONDARY_TDM_TX_6:
	case AFE_PORT_ID_SECONDARY_TDM_RX_7:
	case AFE_PORT_ID_SECONDARY_TDM_TX_7:
	case AFE_PORT_ID_TERTIARY_TDM_RX:
	case AFE_PORT_ID_TERTIARY_TDM_TX:
	case AFE_PORT_ID_TERTIARY_TDM_RX_1:
	case AFE_PORT_ID_TERTIARY_TDM_TX_1:
	case AFE_PORT_ID_TERTIARY_TDM_RX_2:
	case AFE_PORT_ID_TERTIARY_TDM_TX_2:
	case AFE_PORT_ID_TERTIARY_TDM_RX_3:
	case AFE_PORT_ID_TERTIARY_TDM_TX_3:
	case AFE_PORT_ID_TERTIARY_TDM_RX_4:
	case AFE_PORT_ID_TERTIARY_TDM_TX_4:
	case AFE_PORT_ID_TERTIARY_TDM_RX_5:
	case AFE_PORT_ID_TERTIARY_TDM_TX_5:
	case AFE_PORT_ID_TERTIARY_TDM_RX_6:
	case AFE_PORT_ID_TERTIARY_TDM_TX_6:
	case AFE_PORT_ID_TERTIARY_TDM_RX_7:
	case AFE_PORT_ID_TERTIARY_TDM_TX_7:
	case AFE_PORT_ID_QUATERNARY_TDM_RX:
	case AFE_PORT_ID_QUATERNARY_TDM_TX:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_1:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_1:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_2:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_2:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_3:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_3:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_4:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_4:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_5:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_5:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_6:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_6:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_7:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_7:
	case AFE_PORT_ID_QUINARY_TDM_RX:
	case AFE_PORT_ID_QUINARY_TDM_TX:
	case AFE_PORT_ID_QUINARY_TDM_RX_1:
	case AFE_PORT_ID_QUINARY_TDM_TX_1:
	case AFE_PORT_ID_QUINARY_TDM_RX_2:
	case AFE_PORT_ID_QUINARY_TDM_TX_2:
	case AFE_PORT_ID_QUINARY_TDM_RX_3:
	case AFE_PORT_ID_QUINARY_TDM_TX_3:
	case AFE_PORT_ID_QUINARY_TDM_RX_4:
	case AFE_PORT_ID_QUINARY_TDM_TX_4:
	case AFE_PORT_ID_QUINARY_TDM_RX_5:
	case AFE_PORT_ID_QUINARY_TDM_TX_5:
	case AFE_PORT_ID_QUINARY_TDM_RX_6:
	case AFE_PORT_ID_QUINARY_TDM_TX_6:
	case AFE_PORT_ID_QUINARY_TDM_RX_7:
	case AFE_PORT_ID_QUINARY_TDM_TX_7:
	case AFE_PORT_ID_SENARY_MI2S_TX:
	case AFE_PORT_ID_INT0_MI2S_RX:
	case AFE_PORT_ID_INT0_MI2S_TX:
	case AFE_PORT_ID_INT1_MI2S_RX:
	case AFE_PORT_ID_INT1_MI2S_TX:
	case AFE_PORT_ID_INT2_MI2S_RX:
	case AFE_PORT_ID_INT2_MI2S_TX:
	case AFE_PORT_ID_INT3_MI2S_RX:
	case AFE_PORT_ID_INT3_MI2S_TX:
	case AFE_PORT_ID_INT4_MI2S_RX:
	case AFE_PORT_ID_INT4_MI2S_TX:
	case AFE_PORT_ID_INT5_MI2S_RX:
	case AFE_PORT_ID_INT5_MI2S_TX:
	case AFE_PORT_ID_INT6_MI2S_RX:
	case AFE_PORT_ID_INT6_MI2S_TX:
		break;
	default:
		ret = -EINVAL;
	}

	return ret;
}

int q6audio_validate_port(u16 port_id)
{
	int ret;

	switch (port_id) {
	case PRIMARY_I2S_RX:
	case PRIMARY_I2S_TX:
	case AFE_PORT_ID_PRIMARY_PCM_RX:
	case AFE_PORT_ID_PRIMARY_PCM_TX:
	case AFE_PORT_ID_SECONDARY_PCM_RX:
	case AFE_PORT_ID_SECONDARY_PCM_TX:
	case AFE_PORT_ID_TERTIARY_PCM_RX:
	case AFE_PORT_ID_TERTIARY_PCM_TX:
	case AFE_PORT_ID_QUATERNARY_PCM_RX:
	case AFE_PORT_ID_QUATERNARY_PCM_TX:
	case AFE_PORT_ID_QUINARY_PCM_RX:
	case AFE_PORT_ID_QUINARY_PCM_TX:
	case SECONDARY_I2S_RX:
	case SECONDARY_I2S_TX:
	case MI2S_RX:
	case MI2S_TX:
	case HDMI_RX:
	case DISPLAY_PORT_RX:
	case RSVD_2:
	case RSVD_3:
	case DIGI_MIC_TX:
	case VOICE_RECORD_RX:
	case VOICE_RECORD_TX:
	case VOICE_PLAYBACK_TX:
	case VOICE2_PLAYBACK_TX:
	case SLIMBUS_0_RX:
	case SLIMBUS_0_TX:
	case SLIMBUS_1_RX:
	case SLIMBUS_1_TX:
	case SLIMBUS_2_RX:
	case SLIMBUS_2_TX:
	case SLIMBUS_3_RX:
	case SLIMBUS_3_TX:
	case SLIMBUS_4_RX:
	case SLIMBUS_4_TX:
	case SLIMBUS_5_RX:
	case SLIMBUS_5_TX:
	case SLIMBUS_6_RX:
	case SLIMBUS_6_TX:
	case SLIMBUS_7_RX:
	case SLIMBUS_7_TX:
	case SLIMBUS_8_RX:
	case SLIMBUS_8_TX:
	case INT_BT_SCO_RX:
	case INT_BT_SCO_TX:
	case INT_BT_A2DP_RX:
	case INT_FM_RX:
	case INT_FM_TX:
	case RT_PROXY_PORT_001_RX:
	case RT_PROXY_PORT_001_TX:
	case AFE_PORT_ID_PRIMARY_MI2S_RX:
	case AFE_PORT_ID_PRIMARY_MI2S_TX:
	case AFE_PORT_ID_QUATERNARY_MI2S_RX:
	case AFE_PORT_ID_QUATERNARY_MI2S_TX:
	case AFE_PORT_ID_SECONDARY_MI2S_RX:
	case AFE_PORT_ID_SECONDARY_MI2S_TX:
	case AFE_PORT_ID_SPDIF_RX:
	case AFE_PORT_ID_TERTIARY_MI2S_RX:
	case AFE_PORT_ID_TERTIARY_MI2S_TX:
	case AFE_PORT_ID_QUINARY_MI2S_RX:
	case AFE_PORT_ID_QUINARY_MI2S_TX:
	case AFE_PORT_ID_SECONDARY_MI2S_RX_SD1:
	case AFE_PORT_ID_PRIMARY_TDM_RX:
	case AFE_PORT_ID_PRIMARY_TDM_TX:
	case AFE_PORT_ID_PRIMARY_TDM_RX_1:
	case AFE_PORT_ID_PRIMARY_TDM_TX_1:
	case AFE_PORT_ID_PRIMARY_TDM_RX_2:
	case AFE_PORT_ID_PRIMARY_TDM_TX_2:
	case AFE_PORT_ID_PRIMARY_TDM_RX_3:
	case AFE_PORT_ID_PRIMARY_TDM_TX_3:
	case AFE_PORT_ID_PRIMARY_TDM_RX_4:
	case AFE_PORT_ID_PRIMARY_TDM_TX_4:
	case AFE_PORT_ID_PRIMARY_TDM_RX_5:
	case AFE_PORT_ID_PRIMARY_TDM_TX_5:
	case AFE_PORT_ID_PRIMARY_TDM_RX_6:
	case AFE_PORT_ID_PRIMARY_TDM_TX_6:
	case AFE_PORT_ID_PRIMARY_TDM_RX_7:
	case AFE_PORT_ID_PRIMARY_TDM_TX_7:
	case AFE_PORT_ID_SECONDARY_TDM_RX:
	case AFE_PORT_ID_SECONDARY_TDM_TX:
	case AFE_PORT_ID_SECONDARY_TDM_RX_1:
	case AFE_PORT_ID_SECONDARY_TDM_TX_1:
	case AFE_PORT_ID_SECONDARY_TDM_RX_2:
	case AFE_PORT_ID_SECONDARY_TDM_TX_2:
	case AFE_PORT_ID_SECONDARY_TDM_RX_3:
	case AFE_PORT_ID_SECONDARY_TDM_TX_3:
	case AFE_PORT_ID_SECONDARY_TDM_RX_4:
	case AFE_PORT_ID_SECONDARY_TDM_TX_4:
	case AFE_PORT_ID_SECONDARY_TDM_RX_5:
	case AFE_PORT_ID_SECONDARY_TDM_TX_5:
	case AFE_PORT_ID_SECONDARY_TDM_RX_6:
	case AFE_PORT_ID_SECONDARY_TDM_TX_6:
	case AFE_PORT_ID_SECONDARY_TDM_RX_7:
	case AFE_PORT_ID_SECONDARY_TDM_TX_7:
	case AFE_PORT_ID_TERTIARY_TDM_RX:
	case AFE_PORT_ID_TERTIARY_TDM_TX:
	case AFE_PORT_ID_TERTIARY_TDM_RX_1:
	case AFE_PORT_ID_TERTIARY_TDM_TX_1:
	case AFE_PORT_ID_TERTIARY_TDM_RX_2:
	case AFE_PORT_ID_TERTIARY_TDM_TX_2:
	case AFE_PORT_ID_TERTIARY_TDM_RX_3:
	case AFE_PORT_ID_TERTIARY_TDM_TX_3:
	case AFE_PORT_ID_TERTIARY_TDM_RX_4:
	case AFE_PORT_ID_TERTIARY_TDM_TX_4:
	case AFE_PORT_ID_TERTIARY_TDM_RX_5:
	case AFE_PORT_ID_TERTIARY_TDM_TX_5:
	case AFE_PORT_ID_TERTIARY_TDM_RX_6:
	case AFE_PORT_ID_TERTIARY_TDM_TX_6:
	case AFE_PORT_ID_TERTIARY_TDM_RX_7:
	case AFE_PORT_ID_TERTIARY_TDM_TX_7:
	case AFE_PORT_ID_QUATERNARY_TDM_RX:
	case AFE_PORT_ID_QUATERNARY_TDM_TX:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_1:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_1:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_2:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_2:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_3:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_3:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_4:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_4:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_5:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_5:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_6:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_6:
	case AFE_PORT_ID_QUATERNARY_TDM_RX_7:
	case AFE_PORT_ID_QUATERNARY_TDM_TX_7:
	case AFE_PORT_ID_QUINARY_TDM_RX:
	case AFE_PORT_ID_QUINARY_TDM_TX:
	case AFE_PORT_ID_QUINARY_TDM_RX_1:
	case AFE_PORT_ID_QUINARY_TDM_TX_1:
	case AFE_PORT_ID_QUINARY_TDM_RX_2:
	case AFE_PORT_ID_QUINARY_TDM_TX_2:
	case AFE_PORT_ID_QUINARY_TDM_RX_3:
	case AFE_PORT_ID_QUINARY_TDM_TX_3:
	case AFE_PORT_ID_QUINARY_TDM_RX_4:
	case AFE_PORT_ID_QUINARY_TDM_TX_4:
	case AFE_PORT_ID_QUINARY_TDM_RX_5:
	case AFE_PORT_ID_QUINARY_TDM_TX_5:
	case AFE_PORT_ID_QUINARY_TDM_RX_6:
	case AFE_PORT_ID_QUINARY_TDM_TX_6:
	case AFE_PORT_ID_QUINARY_TDM_RX_7:
	case AFE_PORT_ID_QUINARY_TDM_TX_7:
	case AFE_PORT_ID_SENARY_MI2S_TX:
	case AFE_PORT_ID_USB_RX:
	case AFE_PORT_ID_USB_TX:
	case AFE_PORT_ID_INT0_MI2S_RX:
	case AFE_PORT_ID_INT0_MI2S_TX:
	case AFE_PORT_ID_INT1_MI2S_RX:
	case AFE_PORT_ID_INT1_MI2S_TX:
	case AFE_PORT_ID_INT2_MI2S_RX:
	case AFE_PORT_ID_INT2_MI2S_TX:
	case AFE_PORT_ID_INT3_MI2S_RX:
	case AFE_PORT_ID_INT3_MI2S_TX:
	case AFE_PORT_ID_INT4_MI2S_RX:
	case AFE_PORT_ID_INT4_MI2S_TX:
	case AFE_PORT_ID_INT5_MI2S_RX:
	case AFE_PORT_ID_INT5_MI2S_TX:
	case AFE_PORT_ID_INT6_MI2S_RX:
	case AFE_PORT_ID_INT6_MI2S_TX:
	case AFE_PORT_ID_PSEUDOPORT_01:
	{
		ret = 0;
		break;
	}

	default:
		ret = -EINVAL;
	}

	return ret;
}
