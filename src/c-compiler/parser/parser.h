/** Parser
 * @file
 *
 * This source file is part of the Cone Programming Language C compiler
 * See Copyright Notice in conec.h
*/

#ifndef parser_h
#define parser_h

#include "../ast/ast.h"

typedef struct ParseState {
	ModuleAstNode *pgmmod;	// Root module for program
	ModuleAstNode *mod;		// Current module
	NamedAstNode *owner;	// Current namespace owning named nodes
} ParseState;

// When parsing a variable definition, what syntax is allowed?
enum ParseFlags {
	ParseMayName = 0x8000,		// The variable may be named
	ParseMayAnon = 0x4000,		// The variable may be anonymous
	ParseMaySig  = 0x2000,		// The variable may be signature only
	ParseMayImpl = 0x1000		// The variable may implement a code block
};

// parser.c
ModuleAstNode *parsePgm();
ModuleAstNode *parseModuleBlk(ParseState *parse, ModuleAstNode *mod);
AstNode *parseFn(ParseState *parse, int16_t flags);
void parseSemi();
void parseRCurly();
void parseLCurly();
void parseRParen();

// parseflow.c
AstNode *parseIf(ParseState *parse);
AstNode *parseBlock(ParseState *parse);

// parseexpr.c
AstNode *parseExpr(ParseState *parse);

// parsetype.c
PermAstNode *parsePerm(PermAstNode *defperm);
void parseAllocPerm(PtrAstNode *refnode);
NameDclAstNode *parseVarDcl(ParseState *parse, PermAstNode *defperm, int16_t flags);
AstNode *parseFnSig(ParseState *parse);
AstNode *parseStruct(ParseState *parse);
AstNode *parseVtype(ParseState *parse);

#endif
