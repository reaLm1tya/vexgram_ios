#import <Foundation/Foundation.h>

@interface BuildConfigExtra : NSObject

+ (NSDictionary * _Nonnull)signatureDict;
/// Safe variant for sideloaded/AltStore builds: never throws; returns empty dict on parse failure.
+ (NSDictionary * _Nonnull)signatureDictOrEmpty;

@end
