#ifndef SORBET_DSL_REGEXP_H
#define SORBET_DSL_REGEXP_H
#include "ast/ast.h"

namespace sorbet::dsl {

/**
 * This class desugars things of the form
 *
 *   A = Regexp.new(...)
 *
 * into
 *
 *   A = T.let(Regexp.new(...), Regexp)
 *
 */
class Regexp final {
public:
    static std::vector<std::unique_ptr<ast::Expression>> replaceDSL(core::MutableContext ctx, ast::Assign *asgn);

    Regexp() = delete;
};

} // namespace sorbet::dsl

#endif
