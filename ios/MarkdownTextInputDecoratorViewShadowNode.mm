#include <react-native-live-markdown/MarkdownTextInputDecoratorViewShadowNode.h>
#include <react-native-live-markdown/RCTTextLayoutManager+Markdown.h>
#include <react/renderer/components/iostextinput/TextInputShadowNode.h>
#include <react/utils/ManagedObjectWrapper.h>

namespace facebook {
namespace react {

extern const char MarkdownTextInputDecoratorViewComponentName[] = "MarkdownTextInputDecoratorView";

#pragma mark - LayoutableShadowNode

Size MarkdownTextInputDecoratorViewShadowNode::measureContent(
    LayoutContext const &layoutContext,
    LayoutConstraints const &layoutConstraints) const {
  RCTMarkdownUtils *markdownUtils = [[RCTMarkdownUtils alloc] initWithBackedTextInputView:nil];
  const auto &props = *std::static_pointer_cast<MarkdownTextInputDecoratorViewProps const>(getProps());
  RCTMarkdownStyle *markdownStyle = [[RCTMarkdownStyle alloc] initWithStruct:props.markdownStyle];
  [markdownUtils setMarkdownStyle:markdownStyle];
  globalMarkdownUtils = markdownUtils;
  return {};
}

} // namespace react
} // namespace facebook
