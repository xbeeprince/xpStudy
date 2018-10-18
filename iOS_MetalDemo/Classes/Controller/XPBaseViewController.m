//
//  XPBaseViewController.m
//  iOS_MetalDemo
//
//  Created by prince on 2018/10/11.
//  Copyright © 2018 Tencent. All rights reserved.
//

#import "XPBaseViewController.h"
#import "XPBaseMetalView.h"
#include "XPArray.h"


@import simd;
@import MetalKit;

@interface XPBaseViewController () <MTKViewDelegate>
{
    id<MTLCommandQueue> _commandQueue;
}
@property (nonatomic, strong)XPBaseMetalView *mtkView;
@end

@implementation XPBaseViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    _mtkView = [[XPBaseMetalView alloc] initWithFrame:self.view.bounds];
    _mtkView.delegate = self;
    [self.view addSubview:_mtkView];
    
    _commandQueue = [_mtkView.device newCommandQueue];
    
    //c语言测试代码
    {
        NSLog(@"begine");

        XPArray *myArray = AXPArray_Make(float, 10,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0);
        for (int i = 0; i < 10; i++) {
            NSLog(@"%f",AXPArray_Get(myArray,i,float));
        }
        
        
        XPArray myArra2 = AXPArray_Init(float, 10,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0);
        for (int i = 0; i < 10; i++) {
            NSLog(@"%f",AXPArray_Get(&myArra2,i,float));
        }
        int x[1] = (int[1]){
            100
        };
        
        int y = (int){
            100
        };
        
        int size = sizeof(XPArray);
        
        XPArray *myArray3 = AXPArray->Create(sizeof(float),10);
        
        for (int i = 0; i < 10; i++) {
            AXPArray_Set(myArray3,i,i,float);
        }
        
        for (int i = 0; i < 10; i++) {
            float tmp = ((float *)myArray3->data)[i];
            NSLog(@"%f",tmp);
        }
        
        NSLog(@"end");
    }
}

#pragma mark - MTKViewDelegate
-(void)drawInMTKView:(MTKView *)view
{
    MTLClearColor color;
    color.red = 1.0;
    color.green = 1.0;
    color.blue = 1.0;
    color.alpha = 1.0;
    
    view.clearColor = MTLClearColorMake(color.red, color.green, color.blue, color.alpha);
    
    id <MTLCommandBuffer> commandBuffer = [_commandQueue commandBuffer];
    commandBuffer.label = @"MyCommand";
    
    MTLRenderPassDescriptor *renderPassDescroptor = view.currentRenderPassDescriptor;
    if (renderPassDescroptor) {
        id<MTLRenderCommandEncoder> renderEncoder = [commandBuffer renderCommandEncoderWithDescriptor:renderPassDescroptor];
        renderEncoder.label = @"MyRenderEncoder";
        
        [renderEncoder endEncoding];
        [commandBuffer presentDrawable:view.currentDrawable];
    }
    [commandBuffer commit];
}

-(void)mtkView:(MTKView *)view drawableSizeWillChange:(CGSize)size
{
    
}

@end
