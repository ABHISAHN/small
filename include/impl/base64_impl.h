#pragma once

//#include <cstddef>
#include <stdlib.h>
#include <string>
#include <vector>


namespace small
{
    namespace base64
    {
        // get base64 char corresponding in alphabet
        inline char     get_base64char_at           ( unsigned int index )
        {
            //if ( index < 26 )     return char( index + 'A' );
            //else if ( index < 52 )return char( index + ('a' - 26) );
            //else if ( index < 62 )return char( index + '0' - 52 );
            //else if ( index == 62 )return '+';
            //else if ( index == 63 )return '/';
            //return 0;

            static char __base64[] =
            {
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
            };

            return index <= 63 ? __base64[index] : 0;
        }


        // get index of base64 char or -1 if it is not a base64 char
        inline int      get_indexof_base64char      ( unsigned char ch )
        {
            //if ( ch >= 'A' && ch <= 'Z' )     return (ch - 'A');
            //else if ( ch >= 'a' && ch <= 'z' )return (ch - 'a' + 26);
            //else if ( ch >= '0' && ch <= '9' )return (ch - '0' + 52);
            //else if ( ch == '+' )             return 62;
            //else if ( ch == '/' )             return 63;
            //return -1;

            static int __index_of[256] = {
                -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/,
                -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/, -1/*.*/,
                -1/* */, -1/*!*/, -1/*"*/, -1/*#*/, -1/*$*/, -1/*%*/, -1/*&*/, -1/*'*/, -1/*(*/, -1/*)*/, -1/***/, 62/*+*/, -1/*,*/, -1/*-*/, -1/*.*/, 63/*/*/,
                52/*0*/, 53/*1*/, 54/*2*/, 55/*3*/, 56/*4*/, 57/*5*/, 58/*6*/, 59/*7*/, 60/*8*/, 61/*9*/, -1/*:*/, -1/*;*/, -1/*<*/, -1/*=*/, -1/*>*/, -1/*?*/,
                -1/*@*/,  0/*A*/,  1/*B*/,  2/*C*/,  3/*D*/,  4/*E*/,  5/*F*/,  6/*G*/,  7/*H*/,  8/*I*/,  9/*J*/, 10/*K*/, 11/*L*/, 12/*M*/, 13/*N*/, 14/*O*/,
                15/*P*/, 16/*Q*/, 17/*R*/, 18/*S*/, 19/*T*/, 20/*U*/, 21/*V*/, 22/*W*/, 23/*X*/, 24/*Y*/, 25/*Z*/, -1/*[*/, -1/*\*/, -1/*]*/, -1/*^*/, -1/*_*/,
                -1/*`*/, 26/*a*/, 27/*b*/, 28/*c*/, 29/*d*/, 30/*e*/, 31/*f*/, 32/*g*/, 33/*h*/, 34/*i*/, 35/*j*/, 36/*k*/, 37/*l*/, 38/*m*/, 39/*n*/, 40/*o*/,
                41/*p*/, 42/*q*/, 43/*r*/, 44/*s*/, 45/*t*/, 46/*u*/, 47/*v*/, 48/*w*/, 49/*x*/, 50/*y*/, 51/*z*/, -1/*{*/, -1/*|*/, -1/*}*/, -1/*~*/, -1/**/,
                -1/*�*/, -1/*�*/,  -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/,
                -1/*�*/,  -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/,
                -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/,
                -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/,
                -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/,
                -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/,
                -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/,
                -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/, -1/*�*/,
            };

            return __index_of[ch];
        }





        //
        // get base64 buffer needed size (without null ending char)
        // 
        inline size_t   get_base64_size             ( const size_t& length )
        {
            return ((length + 2) / 3) * 4;
        }

        // to base64 (buffer must be proper allocated using get_base64_size + 1)
        inline bool     tobase64                    ( char* base64, const char* src, const size_t& src_length )
        {
            unsigned int    encoded_word = 0;
            int             count_bits = 0;
            int             multiple = 0;
            unsigned int    base64_index = 0;

            char            ch = 0;
            for ( size_t i = 0; i < src_length; ++i, ++src )
            {
                encoded_word = encoded_word << 8 | ((unsigned char)*src);
                count_bits += 8;

                for ( ; count_bits >= 6; )
                {
                    ++multiple;
                    if ( multiple >= 4 )
                        multiple = 0;

                    count_bits -= 6;
                    base64_index = 0x3F & (encoded_word >> (count_bits));

                    ch = get_base64char_at( base64_index );
                    *base64++ = ch;
                }
            }

            // still left something
            if ( multiple > 0 )
            {
                encoded_word = encoded_word << 8 | ((unsigned char)'\0');
                count_bits += 8;

                count_bits -= 6;
                base64_index = 0x3F & (encoded_word >> (count_bits));

                ch = get_base64char_at( base64_index );
                *base64++ = ch;

                //  add '='
                for ( int k = multiple; k < 3; k++ )
                    *base64++ = '=';
            }
            
            return true;
        }




        // get aprox size
        inline size_t   get_decodedbase64_size      ( const size_t& base64_length )
        {
            return ((base64_length + 3) / 4) * 3;
        }

        // decode from base 64 (returns length)
        inline size_t   frombase64                  ( char* decoded_buffer, const char* base64, const size_t& base64_length )
        {
            size_t  decoded_length = 0;

            int     decoded_word = 0;
            int     count_bits = 0;

            for ( size_t i = 0; i < base64_length; ++i, ++base64 )
            {
                const char ch = *base64;
                if ( ch == '=' )
                    break;

                // decode it
                int add = get_indexof_base64char( ch );
                if ( add < 0 )
                    continue;

                decoded_word = decoded_word << 6 | add;
                count_bits += 6;

                if ( count_bits >= 8 )
                {
                    count_bits -= 8;
                    unsigned char decoded_ch = (unsigned char)(0xFF & (decoded_word >> (count_bits)));

                    *decoded_buffer++ = decoded_ch;
                    ++decoded_length;
                }
            }

            return decoded_length;
        }
    }
    
}