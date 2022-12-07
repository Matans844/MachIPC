//
//  Database.h
//  MachPortsServer
//
//  Created by matan on 06/12/2022.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DataManager : NSObject

// NSMapTable should help with weak references to deactivated clients
@property NSMutableDictionary * dictSenderToHash;
@property NSMutableDictionary * dictHashToComponents;
// @property NSMutableDictionary * dictMsgDataHashToMsg;

+ (NSData *) doSha256: (NSData *) dataIn;
+ (NSData *) toNSData: (NSArray *) array;
+ (NSData *) machMessageToSha256: (NSPortMessage *) message;

- (void) initiate;
- (NSMutableDictionary *) getDictSenderToHash;
- (NSMutableDictionary *) getDictHashToComponents;
// - (BOOL) validateDict:(NSMutableDictionary *) dictToValidate;
// - (NSMutableDictionary *) getDictMsgDataHashToMsg;

- (BOOL) saveData: (NSPortMessage *) message;
- (NSData * _Nullable) getData: (NSPort *) sender;
- (BOOL) isStorageVacant: (NSPort *) senderPort;
- (BOOL) isDataValid: (NSPortMessage *) message;
- (BOOL) isSenderActive:(NSPort *)senderPort;

- (void) addToDictSenderToHash: (NSPortMessage *) message;
- (void) addToDictHashToComponents: (NSPortMessage *) message;
// - (void) addToDictMsgDataHashToMsg: (NSPortMessage *) message;


@end

NS_ASSUME_NONNULL_END
