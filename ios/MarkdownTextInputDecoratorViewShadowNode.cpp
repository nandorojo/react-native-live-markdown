#include <react-native-live-markdown/MarkdownTextInputDecoratorViewShadowNode.h>
#include <react/renderer/components/iostextinput/TextInputShadowNode.h>

namespace facebook {
namespace react {

extern const char MarkdownTextInputDecoratorViewComponentName[] = "MarkdownTextInputDecoratorView";

#pragma mark - LayoutableShadowNode

void MarkdownTextInputDecoratorViewShadowNode::layout(LayoutContext layoutContext) {
  ensureUnsealed();

  const auto &affectedNodes = *layoutContext.affectedNodes;
  auto size = affectedNodes.size();
  assert(size >= 2);
  auto shadowNode = affectedNodes[size - 2];
  auto textInputShadowNode = dynamic_cast<TextInputShadowNode *>(const_cast<LayoutableShadowNode *>(shadowNode));
  assert(textInputShadowNode != nullptr);

  textInputShadowNode->setTextLayoutManager(std::make_shared<TextLayoutManager>(nullptr));
  textInputShadowNode->ensureUnsealed();
  textInputShadowNode->layout(layoutContext);

  ConcreteViewShadowNode::layout(layoutContext);
}

} // namespace react
} // namespace facebook
