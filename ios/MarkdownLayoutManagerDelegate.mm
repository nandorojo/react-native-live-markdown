#import <react-native-live-markdown/MarkdownLayoutManagerDelegate.h>
#import <react-native-live-markdown/BlockquoteLayoutFragment.h>

@implementation MarkdownLayoutManagerDelegate

- (NSTextLayoutFragment *)textLayoutManager:(NSTextLayoutManager *)textLayoutManager
              textLayoutFragmentForLocation:(id<NSTextLocation>)location
                              inTextElement:(NSTextElement *)textElement
{
  return [[BlockquoteLayoutFragment alloc] initWithTextElement:textElement range:textElement.elementRange];
}

@end
