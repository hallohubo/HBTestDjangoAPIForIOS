//
//  HBMainVC.m
//  HBTestDjangoAPI
//
//  Created by 胡勃 on 6/10/19.
//  Copyright © 2019 胡勃. All rights reserved.
//

#import "HBMainVC.h"

@interface HBMainVC ()
{
    IBOutlet UIButton   *btnTest;
}

@end

@implementation HBMainVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

#pragma mark - UI event

- (IBAction)btnClick:(UIButton *)sender
{
    NSLog(@"touch a button!");
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
