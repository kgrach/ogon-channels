#include "smartcard_message.h"

ReaderState::ReaderState(): _dwCurrentState(0), _dwEventState(0), _cbAtr(0){
    _rgbAtr.fill('\0', 36);
}

ReaderState_Return::ReaderState_Return(): _dwCurrentState(0), _dwEventState(0), _cbAtr(0){
    _rgbAtr.fill('\0', 36);
}