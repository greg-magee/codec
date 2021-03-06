/*
 * Copyright 2014-2018 Neueda Ltd.
 * 
 * Generated 21/05/2019
 */
#ifndef EUREX_USERLOGINREQUEST_PACKET_H
#define EUREX_USERLOGINREQUEST_PACKET_H

#include <string>
#include <vector>
#include <sstream>
#include <cstddef>
#include <stdint.h>
#include "eurexPackets.h"
#include "EtiPacketUtils.h"

namespace neueda
{

using namespace std;

class eurexUserLoginRequestPacket
{
    public:
        // no value constants
        static const int32_t USERNAME_MIN;
        static const int32_t USERNAME_MAX;
        static const int32_t USERNAME_NO_VALUE;
        static const char PASSWORD_NO_VALUE[32];
        static const size_t PASSWORD_MAX_LENGTH;
        static const char PAD4_NO_VALUE[4];
        static const size_t PAD4_MAX_LENGTH;

        // fields (use with care)
        eurexMessageHeaderInCompPacket mMessageHeaderIn;
        eurexRequestHeaderCompPacket mRequestHeader;
        int32_t mUsername;
        char mPassword[32];
        char mPad4[4];

        // constructor
        eurexUserLoginRequestPacket ()
        {
            mMessageHeaderIn.mTemplateID = 10018;
            mUsername = USERNAME_NO_VALUE;
            memcpy(mPassword, PASSWORD_NO_VALUE, sizeof (mPassword));
            memcpy(mPad4, PAD4_NO_VALUE, sizeof (mPad4));
        }

        // getters & setters
        const eurexMessageHeaderInCompPacket& getMessageHeaderIn () const
        {
            return mMessageHeaderIn;
        }

        bool setMessageHeaderIn (const eurexMessageHeaderInCompPacket& v)
        {
            mMessageHeaderIn = v;
            return true;
        }

        const eurexRequestHeaderCompPacket& getRequestHeader () const
        {
            return mRequestHeader;
        }

        bool setRequestHeader (const eurexRequestHeaderCompPacket& v)
        {
            mRequestHeader = v;
            return true;
        }

        int32_t getUsername () const
        {
            return mUsername;
        }

        bool setUsername (int32_t v)
        {
            mUsername = v;
            return ((USERNAME_MIN <= mUsername && mUsername <= USERNAME_MAX) || mUsername == USERNAME_NO_VALUE);
        }

        bool isUsernameValid () const
        {
            return (mUsername != USERNAME_NO_VALUE);
        }

        void resetUsername ()
        {
            mUsername = USERNAME_NO_VALUE;
        }

        string getPassword () const
        {
            string result;
            for (size_t i = 0; mPassword[i] && i < PASSWORD_MAX_LENGTH; i++)
                result += (mPassword[i]);
            return result;
        }

        bool setPassword (const string& v)
        {
            memset (mPassword, '\0', sizeof (mPassword));
            size_t size = min ((size_t) v.size (), (size_t) PASSWORD_MAX_LENGTH);
            strncpy (mPassword, v.c_str (), size);
            return (v.size () <= PASSWORD_MAX_LENGTH);
        }

        bool isPasswordValid () const
        {
            return (memcmp (mPassword, PASSWORD_NO_VALUE, sizeof (mPassword)) != 0);
        }

        void resetPassword ()
        {
            memcpy (mPassword, PASSWORD_NO_VALUE, sizeof (mPassword));
        }

        string getPad4 () const
        {
            return string (mPad4, PAD4_MAX_LENGTH);
        }

        bool setPad4 (const string& v)
        {
            memset (mPad4, '\0', sizeof (mPad4));
            size_t size = min ((size_t) v.size (), (size_t) PAD4_MAX_LENGTH);
            strncpy (mPad4, v.c_str (), size);
            return (v.size () <= PAD4_MAX_LENGTH);
        }

        bool isPad4Valid () const
        {
            return (memcmp (mPad4, PAD4_NO_VALUE, sizeof (mPad4)) != 0);
        }

        void resetPad4 ()
        {
            memcpy (mPad4, PAD4_NO_VALUE, sizeof (mPad4));
        }


        // render current raw size
        size_t getRawSize () const
        {
            size_t result = mMessageHeaderIn.getRawSize()
                + mRequestHeader.getRawSize()
                + sizeof (mUsername)
                + sizeof (mPassword)
                + sizeof (mPad4);
            return result;
        }

        // serialization
        codecState serialize (void *buf, size_t len, size_t &used)
        {
            mMessageHeaderIn.mBodyLen = getRawSize ();
            codecState state;
            state = mMessageHeaderIn.serialize (buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = mRequestHeader.serialize (buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eti::serialize (mUsername, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eti::serialize (mPassword, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eti::serialize (mPad4, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            return GW_CODEC_SUCCESS;
        }

        // deserialization
        codecState deserialize (const void *buf, size_t len, size_t &used)
        {
            codecState state;
            state = mMessageHeaderIn.deserialize (buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = mRequestHeader.deserialize (buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eti::deserialize (mUsername, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eti::deserialize (mPassword, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            state = eti::deserialize (mPad4, buf, len, used);
            if (state != GW_CODEC_SUCCESS) return state;
            mMessageHeaderIn.mBodyLen = getRawSize ();
            return GW_CODEC_SUCCESS;
        }

        // string conversion
        string toString () const
        {
            stringstream sss;
            sss << "UserLoginRequest::"
                << "[MessageHeaderIn=" << mMessageHeaderIn.toString () << "],"
                << "[RequestHeader=" << mRequestHeader.toString () << "],"
                << "[Username=" << getUsername () << "],"
                << "[Password=" << getPassword () << "],"
                << "[Pad4=" << getPad4 () << "]";
            return sss.str();
        }
};

const int32_t eurexUserLoginRequestPacket::USERNAME_MIN = 0;
const int32_t eurexUserLoginRequestPacket::USERNAME_MAX = 2147483647;
const int32_t eurexUserLoginRequestPacket::USERNAME_NO_VALUE = 0xFFFFFFFF;
const char eurexUserLoginRequestPacket::PASSWORD_NO_VALUE[32] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const size_t eurexUserLoginRequestPacket::PASSWORD_MAX_LENGTH = 32;
const char eurexUserLoginRequestPacket::PAD4_NO_VALUE[4] = {0x00, 0x00, 0x00, 0x00};
const size_t eurexUserLoginRequestPacket::PAD4_MAX_LENGTH = 4;


} // namespace neueda

#endif // EUREX_USERLOGINREQUEST_PACKET_H
