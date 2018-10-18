//
//  XPBaseMetalView.m
//  iOS_MetalDemo
//
//  Created by prince on 2018/10/11.
//  Copyright © 2018 Tencent. All rights reserved.
//

#import "XPBaseMetalView.h"

@implementation XPBaseMetalView

-(instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        [self setup];
    }
    return self;
}

-(void)setup
{
    self.device = MTLCreateSystemDefaultDevice();
    self.preferredFramesPerSecond = 60;
}

@end
