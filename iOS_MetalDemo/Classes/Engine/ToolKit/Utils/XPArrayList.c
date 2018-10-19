//
//  XPArrayList.c
//  iOS_MetalDemo
//
//  Created by prince on 2018/10/19.
//  Copyright © 2018 Tencent. All rights reserved.
//

#include "XPArrayList.h"
#include <stdlib.h>
#include <string.h>

static inline void _initArrayList(int elementTypeSize, XPArrayList* arrayList)
{
    arrayList->elementArray->data = NULL;
    arrayList->elementArray->lenght = 0;
    arrayList->elementTypeSize = elementTypeSize;
    arrayList->size = 0;
    arrayList->increase = 10;
}

static inline void _addCapacity(XPArrayList* arrayList, int increase)
{
    void* data = realloc(arrayList->elementArray->data, (increase + arrayList->elementArray->lenght) * arrayList->elementTypeSize);
    arrayList->elementArray->data = data;
    arrayList->elementArray->lenght += increase;
}

static inline void* _getAdd(XPArrayList* arrayList)
{
    if (arrayList->size == arrayList->elementArray->lenght) {
        _addCapacity(arrayList, arrayList->increase);
    }
    
    return (char *)arrayList->elementArray->data + arrayList->elementTypeSize * (arrayList->size++);
}

static inline void* _getInsert(XPArrayList* arrayList, int index)
{
    if (arrayList->size == arrayList->elementArray->lenght) {
        _addCapacity(arrayList, arrayList->increase);
    }
    
    void* from = (char*)arrayList->elementArray->data + arrayList->elementTypeSize * index;
    void* to = (char*)from + arrayList->elementTypeSize;
    
    memmove(to,from,arrayList->elementTypeSize * (arrayList->size - index));
    arrayList->size++;
    
    return from;
}

static XPArrayList* create(int elementTypeSize)
{
    XPArrayList* arrayList = (XPArrayList*) malloc(sizeof(XPArrayList));
    _initArrayList(elementTypeSize, arrayList);
    
    return arrayList;
}

static XPArrayList* createWithSize(int elementTypeSize, int size)
{
    
}

static void init(int elementTypeSize, XPArrayList* outArrayList)
{
    _initArrayList(elementTypeSize, outArrayList);
}


