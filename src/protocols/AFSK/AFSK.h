#if !defined(_RADIOLIB_AFSK_H)
#define _RADIOLIB_AFSK_H

#include "../../TypeDef.h"

#if !defined(RADIOLIB_EXCLUDE_AFSK)

#include "../../Module.h"

#include "../PhysicalLayer/PhysicalLayer.h"

/*!
  \class AFSKClient

  \brief Client for audio-based transmissions. Requires Arduino tone() function, and a module capable of direct mode transmission using DIO pins.
*/
class AFSKClient  {
  public:
    /*!
      \brief Default contructor.

      \param phy Pointer to the wireless module providing PhysicalLayer communication.

      \param pin The pin that will be used for audio output.
    */
    AFSKClient(PhysicalLayer* phy, RADIOLIB_PIN_TYPE pin);

    /*!
      \brief Initialization method.

      \returns \ref status_codes
    */
    int16_t begin();

    /*!
      \brief Start transmitting audio tone.

      \param freq Frequency of the tone in Hz.

      \param autoStart Whether to automatically enter transmission mode. Defaults to true.

      \returns \ref status_codes
    */
    int16_t tone(uint16_t freq, bool autoStart = true);

    /*!
      \brief Stops transmitting audio tone.

      \param freq Keep transmitter on - this may limit noise when switching transmitter on or off.

      \returns \ref status_codes
    */
    int16_t noTone(bool keepOn = false);

    int16_t emulateTone(float baseFreq, uint8_t* bits, size_t len);

#if !defined(RADIOLIB_GODMODE)
  private:
#endif
    PhysicalLayer* _phy;
    RADIOLIB_PIN_TYPE _pin;

    // allow specific classes access the private PhysicalLayer pointer
    friend class RTTYClient;
    friend class MorseClient;
    friend class HellClient;
    friend class SSTVClient;
    friend class AX25Client;
    friend class FSK4Client;
};

#endif

#endif
