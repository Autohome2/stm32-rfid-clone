#ifndef SUMP_H
#define	SUMP_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

  typedef struct {
    uint16_t delay;
    uint8_t channel;
    uint8_t level;
    uint8_t serial;
    uint8_t start;
  } sump_config;

  typedef struct {
    uint8_t inverted : 1;
    uint8_t external : 1;
    uint8_t channelGroup0 : 1;
    uint8_t channelGroup1 : 1;
    uint8_t channelGroup2 : 1;
    uint8_t channelGroup3 : 1;
    uint8_t filter : 1;
    uint8_t demux : 1;
    uint8_t rle : 1;
  } sump_flags;

  int g_sump_enabled;
  uint8_t g_sump_trigger[4];
  uint8_t g_sump_trigger_values[4];
  sump_config g_sump_config;
  uint32_t g_sump_divider;
  uint16_t g_sump_read_count;
  uint16_t g_sump_delay_count;
  sump_flags g_sump_flags;

  void sump_setup();
  void sump_loop();
  void sump_tx(uint8_t data);


#ifdef	__cplusplus
}
#endif

#endif	/* SUMP_H */
