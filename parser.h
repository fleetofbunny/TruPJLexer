#ifndef PARSER_H
#define PARSER_H

// The parser needs to access token attributes.
#include "token.h"
#include "keywordtoken.h"
#include "punctoken.h"
#include "reloptoken.h"
#include "addoptoken.h"
#include "muloptoken.h"
#include "idtoken.h"
#include "numtoken.h"
#include "eoftoken.h"
#include "scanner.h"

// To print error messages.
#include <iostream>

//using namespace std;

class Parser {
   public:
      Parser (Scanner *the_scanner);
      ~Parser();
  
      bool parse_program();

      // Return true if current token is EOF
      bool done_with_input();
  
   private:

      bool parse_decl_list();
      
      bool parse_variable_decl_list();

      bool parse_variable_decl();

      bool parse_procedure_decl_list();

      bool parse_identifier_list();

      bool parse_identifier_list_prm();

      bool parse_standard_type();

      bool parse_block();

      bool parse_procedure_decl();

      bool parse_procedure_args();

      bool parse_formal_parm_list();

      bool parse_formal_parm_list_hat();

      bool parse_stmt_list();

      bool parse_stmt_list_prm();

      bool parse_stmt();

      bool parse_ad_hoc_as_pc_tail();

      bool parse_if_stmt();

      bool parse_if_stmt_hat();

      bool parse_while_stmt();

      bool parse_print_stmt();

      bool parse_expr_list();

      bool parse_actual_parm_list();

      bool parse_actual_parm_list_hat();

      bool parse_expr();

      bool parse_expr_hat();

      bool parse_simple_expr();

      bool parse_simple_expr_prm();

      bool parse_term();

      bool parse_term_prm();

      bool parse_factor();

      bool parse_sign();
  
      // The lexical analyzer
      Scanner *lex;
      // The current token the parser is looking at
      Token *word;
  
      /* Print out a parse error message:
	 
	 "Parse error: Expected *expected*, found *found*."

	 This method should delete the string after it has printed the
	 error message. */
      void parse_error (string *expected, Token *found);

      // Other helper functions that you may define
  
};

#endif

