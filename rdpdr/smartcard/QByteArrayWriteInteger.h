#pragma once

#include <qglobal.h>
#include <qbytearray.h>

typedef union{
    uint16_t u16;
    uint8_t u8s[2];
}uint8_16_t;

typedef union{
    uint32_t u32;
    uint16_t u16s[2];
}uint16_32_t;

typedef union{
    uint64_t u64;
    uint32_t u32s[2];
}uint32_64_t;

// little-endian
QByteArray &operator<<(QByteArray &l, quint8 r){
    l.append(r);
    return l;
}

// little-endian
QByteArray &operator<<(QByteArray &l, quint16 r){
    const uint8_16_t v= {.u16=r}; //v means val
    return l<<v.u8s[0]<<v.u8s[1];
}

// little-endian
QByteArray &operator<<(QByteArray &l, quint32 r){
    const uint16_32_t v= {.u32=r};
    return l<<v.u16s[0]<<v.u16s[1];
}

// little-endian
QByteArray &operator<<(QByteArray &l, quint64 r){
    const uint32_64_t v= {.u64=r};
    return l<<v.u32s[0]<<v.u32s[1];
}