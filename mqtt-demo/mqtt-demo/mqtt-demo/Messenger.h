//
//  Messenger.h
//  MQTTTest
//
//  Created by Bryan Boyd on 12/6/13.
//  Copyright (c) 2013 Bryan Boyd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MqttOCClient.h"

@interface Messenger : NSObject {
    MqttClient *client;
}

@property (nonatomic, retain) MqttClient *client;
@property (nonatomic, retain) NSString *clientID;
@property NSMutableArray *logMessages;
@property NSMutableArray *subscriptionData;

+ (id)sharedMessenger;
- (void)connectWithHosts:(NSArray *)hosts ports:(NSArray *)ports clientId:(NSString *)clientId cleanSession:(BOOL)cleanSession;
- (void)publish:(NSString *)topic payload:(NSString *)payload qos:(int)qos retained:(BOOL)retained;
- (void)subscribe:(NSString *)topicFilter qos:(int)qos;
- (void)unsubscribe:(NSString *)topicFilter;
- (void)disconnectWithTimeout:(int)timeout;
- (void)clearLog;
- (void)addLogMessage:(NSString *)data type:(NSString *)type;
- (void) showAlert:(NSString*)action :(NSString*) message :(NSString*) pos :(NSString*) neg :(NSString*) title;

@end
