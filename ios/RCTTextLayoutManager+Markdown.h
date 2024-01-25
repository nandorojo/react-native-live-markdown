// This guard prevent this file to be compiled in the old architecture.
#ifdef RCT_NEW_ARCH_ENABLED

#import <react/renderer/textlayoutmanager/RCTTextLayoutManager.h>
#import <react-native-live-markdown/RCTMarkdownUtils.h>

NS_ASSUME_NONNULL_BEGIN

@interface RCTTextLayoutManager (Markdown)

@property(nonatomic, nullable, getter=getMarkdownUtils) RCTMarkdownUtils *markdownUtils;

- (NSAttributedString *)_nsAttributedStringFromAttributedString:(facebook::react::AttributedString)attributedString;

@end

NS_ASSUME_NONNULL_END

#endif /* RCT_NEW_ARCH_ENABLED */
