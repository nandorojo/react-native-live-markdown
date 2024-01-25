// This guard prevent this file to be compiled in the old architecture.
#ifdef RCT_NEW_ARCH_ENABLED

#import <react-native-live-markdown/RCTTextLayoutManager+Markdown.h>
#import <react-native-live-markdown/RCTMarkdownUtils.h>
#import <objc/runtime.h>

using namespace facebook::react;

@implementation RCTTextLayoutManager (Markdown)

- (void)setMarkdownUtils:(RCTMarkdownUtils *)markdownUtils {
  objc_setAssociatedObject(self, @selector(getMarkdownUtils), markdownUtils, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (RCTMarkdownUtils *)getMarkdownUtils {
  return objc_getAssociatedObject(self, @selector(getMarkdownUtils));
}

- (NSAttributedString *)markdown__nsAttributedStringFromAttributedString:(facebook::react::AttributedString)attributedString
{
  NSAttributedString *result = [self markdown__nsAttributedStringFromAttributedString:attributedString];

  if (globalMarkdownUtils != nil) {
    result = [globalMarkdownUtils parseMarkdown:result];
    globalMarkdownUtils = nil;
    // TODO: thread-local
  }

  return result;
}

+ (void)load
{
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
    Class cls = [self class];
    SEL originalSelector = @selector(_nsAttributedStringFromAttributedString:);
    SEL swizzledSelector = @selector(markdown__nsAttributedStringFromAttributedString:);
    Method originalMethod = class_getInstanceMethod(cls, originalSelector);
    Method swizzledMethod = class_getInstanceMethod(cls, swizzledSelector);
    method_exchangeImplementations(originalMethod, swizzledMethod);
  });
}

@end

#endif /* RCT_NEW_ARCH_ENABLED */
