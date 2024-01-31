#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MarkdownLayoutManagerDelegate : NSObject <NSTextLayoutManagerDelegate>

- (NSTextLayoutFragment *)textLayoutManager:(NSTextLayoutManager *)textLayoutManager
              textLayoutFragmentForLocation:(id<NSTextLocation>)location
                              inTextElement:(NSTextElement *)textElement API_AVAILABLE(ios(15.0));

@end

NS_ASSUME_NONNULL_END
