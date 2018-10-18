//
//  XPArray.h
//  iOS_MetalDemo
//
//  Created by prince on 2018/10/18.
//  Copyright © 2018 Tencent. All rights reserved.
//

#ifndef XPArray_h
#define XPArray_h

#include <stdio.h>

typedef struct {
    void *data;
    int lenght;
}XPArray;


struct AXPArray {
  
    XPArray* (*Create)(int elementTypeSize, int lenght);
};

extern struct AXPArray AXPArray[1];

#define XPArray(elementType) XPArray

#define AXPArray_Make(elementType, lenght, ...) \
    (XPArray[1])                                \
    {                                           \
        (elementType[lenght]){__VA_ARGS__},     \
        lenght,                                 \
    }                                           \


#define AXPArray_Init(elementType, length, ...) \
    {                                           \
        (elementType[length]) {__VA_ARGS__},    \
        length,                                 \
    }

#define AXPArray_GetData(array, elementType) \
(elementType*) ((array)->data)


#define AXPArray_Get(array, index, elementType) \
(AXPArray_GetData(array, elementType))[index]

#define AXPArray_GetPtr(array, index, elementType) \
(AXPArray_GetData(array, elementType) + (index))

#define AXPArray_Set(array, index, element, elementType) \
AXPArray_Get(array, index, elementType) = element

#endif /* XPArray_h */
