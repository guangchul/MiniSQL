%{
#include <stdio.h>
#include <string.h>
#include "../node/parseNodes.h"
#include "ptype.h"
void yyerror(yyscan_t yyscanner, char *str);
int flexable(int type);
int calcLength(int type, int length);
char* fnc_itoa(int number);
typedef union YYSTYPE YYSTYPE;
extern int yylex (YYSTYPE * yylval_param , yyscan_t yyscanner);
%}

%pure-parser
%lex-param   {yyscan_t yyscanner}
%parse-param	{yyscan_t yyscanner}

%union
{
	core_YYSTYPE		core_yystype;
	/* these fields must match core_YYSTYPE: */
	int					ival;
	char				*str;
	char				*keyword;
	Node				*node;
	TableNode			*tableNode;
	CreateStmt			*createStmt;
	ColumnNode			*columnNode;
	List				*list;
	InsertStmt			*insertStmt;
	OptTarget			*optTarget;
	SelectStmt			*selectStmt;
	WhereSingle			*whereSingle;
	UpdateStmt			*updateStmt;
}

%type <ival> TypeName Iconst Nullable
%type <columnNode> columnDef
%type <createStmt> CreateStmt
%type <tableNode> table_name
%type <str> ColId singleValue condition_op
%type <keyword> unreserved_keyword
%type <keyword> col_name_keyword reserved_keyword 
%type <list> TableElementList identList columnsList opt_target_list from_list from_clause where_list where_clause update_where_clause simple_where_list
%type <node> stmt
%type <list> multi multiValue valuesList update_value_list
%type <insertStmt> InsertStmt
%type <optTarget> opt_target opt_target_all opt_target_normal opt_target_as opt_target_no_as
%type <selectStmt> SelectStmt
%type <whereSingle> where_single simple_where_single
%type <updateStmt> UpdateStmt


%token <str>	IDENT FCONST SCONST BCONST XCONST Op
%token <ival>	ICONST PARAM
%token			TYPECAST DOT_DOT COLON_EQUALS EQUALS_GREATER
%token			LESS_EQUALS GREATER_EQUALS NOT_EQUALS

/*
 * If you want to make any keyword changes, update the keyword table in
 * src/include/parser/kwlist.h and add new keywords to the appropriate one
 * of the reserved-or-not-so-reserved keyword lists, below; search
 * this file for "Keyword category lists".
 */

/* ordinary key words in alphabetical order */
%token <keyword> ABORT_P ABSOLUTE_P ACCESS ACTION ADD_P ADMIN AFTER
	AGGREGATE ALL ALSO ALTER ALWAYS ANALYSE ANALYZE AND ANY ARRAY AS ASC
	ASSERTION ASSIGNMENT ASYMMETRIC AT ATTACH ATTRIBUTE AUTHORIZATION

	BACKWARD BEFORE BEGIN_P BETWEEN BIGINT BINARY BIT
	BOOLEAN_P BOTH BY

	CACHE CALL CALLED CASCADE CASCADED CASE CAST CATALOG_P CHAIN CHAR_P
	CHARACTER CHARACTERISTICS CHECK CHECKPOINT CLASS CLOSE
	CLUSTER COALESCE COLLATE COLLATION COLUMN COLUMNS COMMENT COMMENTS COMMIT
	COMMITTED CONCURRENTLY CONFIGURATION CONFLICT CONNECTION CONSTRAINT
	CONSTRAINTS CONTENT_P CONTINUE_P CONVERSION_P COPY COST CREATE
	CROSS CSV CUBE CURRENT_P
	CURRENT_CATALOG CURRENT_DATE CURRENT_ROLE CURRENT_SCHEMA
	CURRENT_TIME CURRENT_TIMESTAMP CURRENT_USER CURSOR CYCLE

	DATA_P DATABASE DAY_P DEALLOCATE DEC DECIMAL_P DECLARE DEFAULT DEFAULTS
	DEFERRABLE DEFERRED DEFINER DELETE_P DELIMITER DELIMITERS DEPENDS DESC
	DETACH DICTIONARY DISABLE_P DISCARD DISTINCT DO DOCUMENT_P DOMAIN_P
	DOUBLE_P DROP

	EACH ELSE ENABLE_P ENCODING ENCRYPTED END_P ENUM_P ESCAPE EVENT EXCEPT
	EXCLUDE EXCLUDING EXCLUSIVE EXECUTE EXISTS EXPLAIN
	EXTENSION EXTERNAL EXTRACT

	FALSE_P FAMILY FETCH FILTER FIRST_P FLOAT_P FOLLOWING FOR
	FORCE FOREIGN FORWARD FREEZE FROM FULL FUNCTION FUNCTIONS

	GENERATED GLOBAL GRANT GRANTED GREATEST GROUP_P GROUPING GROUPS

	HANDLER HAVING HEADER_P HOLD HOUR_P

	IDENTITY_P IF_P ILIKE IMMEDIATE IMMUTABLE IMPLICIT_P IMPORT_P IN_P INCLUDE
	INCLUDING INCREMENT INDEX INDEXES INHERIT INHERITS INITIALLY INLINE_P
	INNER_P INOUT INPUT_P INSENSITIVE INSERT INSTEAD INT_P INTEGER
	INTERSECT INTERVAL INTO INVOKER IS ISNULL ISOLATION

	JOIN

	KEY

	LABEL LANGUAGE LARGE_P LAST_P LATERAL_P
	LEADING LEAKPROOF LEAST LEFT LEVEL LIKE LIMIT LISTEN LOAD LOCAL
	LOCALTIME LOCALTIMESTAMP LOCATION LOCK_P LOCKED LOGGED

	MAPPING MATCH MATERIALIZED MAXVALUE METHOD MINUTE_P MINVALUE MODE MONTH_P MOVE

	NAME_P NAMES NATIONAL NATURAL NCHAR NEW NEXT NO NONE
	NOT NOTHING NOTIFY NOTNULL NOWAIT NULL_P NULLIF
	NULLS_P NUMERIC

	OBJECT_P OF OFF OFFSET OIDS OLD ON ONLY OPERATOR OPTION OPTIONS OR
	ORDER ORDINALITY OTHERS OUT_P OUTER_P
	OVER OVERLAPS OVERLAY OVERRIDING OWNED OWNER

	PARALLEL PARSER PARTIAL PARTITION PASSING PASSWORD PLACING PLANS POLICY
	POSITION PRECEDING PRECISION PRESERVE PREPARE PREPARED PRIMARY
	PRIOR PRIVILEGES PROCEDURAL PROCEDURE PROCEDURES PROGRAM PUBLICATION

	QUOTE

	RANGE READ REAL REASSIGN RECHECK RECURSIVE REF_P REFERENCES REFERENCING
	REFRESH REINDEX RELATIVE_P RELEASE RENAME REPEATABLE REPLACE REPLICA
	RESET RESTART RESTRICT RETURNING RETURNS REVOKE RIGHT ROLE ROLLBACK ROLLUP
	ROUTINE ROUTINES ROW ROWS RULE

	SAVEPOINT SCHEMA SCHEMAS SCROLL SEARCH SECOND_P SECURITY SELECT SEQUENCE SEQUENCES
	SERIALIZABLE SERVER SESSION SESSION_USER SET SETS SETOF SHARE SHOW
	SIMILAR SIMPLE SKIP SMALLINT SNAPSHOT SOME SQL_P STABLE STANDALONE_P
	START STATEMENT STATISTICS STDIN STDOUT STORAGE STORED STRICT_P STRIP_P
	SUBSCRIPTION SUBSTRING SUPPORT SYMMETRIC SYSID SYSTEM_P

	TABLE TABLES TABLESAMPLE TABLESPACE TEMP TEMPLATE TEMPORARY TEXT_P THEN
	TIES TIME TIMESTAMP TO TRAILING TRANSACTION TRANSFORM
	TREAT TRIGGER TRIM TRUE_P
	TRUNCATE TRUSTED TYPE_P TYPES_P

	UNBOUNDED UNCOMMITTED UNENCRYPTED UNION UNIQUE UNKNOWN UNLISTEN UNLOGGED
	UNTIL UPDATE USER USING

	VACUUM VALID VALIDATE VALIDATOR VALUE_P VALUES VARCHAR_P VARIADIC VARYING
	VERBOSE VERSION_P VIEW VIEWS VOLATILE

	WHEN WHERE WHITESPACE_P WINDOW WITH WITHIN WITHOUT WORK WRAPPER WRITE

	XML_P XMLATTRIBUTES XMLCONCAT XMLELEMENT XMLEXISTS XMLFOREST XMLNAMESPACES
	XMLPARSE XMLPI XMLROOT XMLSERIALIZE XMLTABLE

	YEAR_P YES_P

	ZONE

/*
 * The grammar thinks these are keywords, but they are not in the kwlist.h
 * list and so can never be entered directly.  The filter in parser.c
 * creates these tokens when required (based on looking one token ahead).
 *
 * NOT_LA exists so that productions such as NOT LIKE can be given the same
 * precedence as LIKE; otherwise they'd effectively have the same precedence
 * as NOT, at least with respect to their left-hand subexpression.
 * NULLS_LA and WITH_LA are needed to make the grammar LALR(1).
 */
%token		NOT_LA NULLS_LA WITH_LA

%%

multi: stmt
	{
		List* list = (List*)newList();
		lappend(list, $1);
		$$ = list;
		(*((yy_extra_type **) (yyscanner)))->list = (void*)list;
	}
	| multi ';' stmt
	{
		if($3 != (void*)0){
			lappend($1, $3);
			$$ = $1;
			(*((yy_extra_type **) (yyscanner)))->list = (void*)$1;
		}
	}
	;

stmt:CreateStmt {$$ = (Node*)$1;}
	|InsertStmt {$$ = (Node*)$1;}
	|SelectStmt {$$ = (Node*)$1;}
	|UpdateStmt {$$ = (Node*)$1;}
	| {$$ = (void*)0;}
	;
	
UpdateStmt: UPDATE ColId SET update_value_list update_where_clause
	{
		UpdateStmt* updateStmt = (UpdateStmt*)makeNode(UpdateStmt);
		FromClause* fromClause = (FromClause*)makeNode(FromClause);
		fromClause->name = $2;
		updateStmt->fromClause = fromClause;
		updateStmt->updateValueList = $4;
		updateStmt->whereClause = $5;
		$$ = updateStmt;
	}
	;
	
update_value_list: ColId '=' singleValue
	{
		UpdateValue* updateValue = (UpdateValue*)makeNode(UpdateValue);
		updateValue->filed = $1;
		updateValue->val = $3;
		List* list = (List*)newList();
		lappend(list, updateValue);
		$$ = list;
		
	}
	| update_value_list ',' ColId '=' singleValue
	{
		UpdateValue* updateValue = (UpdateValue*)makeNode(UpdateValue);
		updateValue->filed = $3;
		updateValue->val = $5;
		lappend($1, updateValue);
		$$ = $1;
	}
	;
	
update_where_clause: WHERE simple_where_list {$$ = $2;}
	| {$$ = (void*)0;}
	;
	
simple_where_list: simple_where_single
	{
		List* list = (List*)newList();
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 0;
		whereCondition->whereSingle = $1;
		lappend(list, whereCondition);
		$$ = list;
	}
	| simple_where_list AND simple_where_single
	{
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 0;
		whereCondition->whereSingle = $3;
		lappend($1, whereCondition);
		$$ = $1;
	}
	| simple_where_list OR simple_where_single
	{
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 2;
		whereCondition->isList = 0;
		whereCondition->whereSingle = $3;
		lappend($1, whereCondition);
		$$ = $1;
	}
	| '(' simple_where_list ')'
	{
		List* list = (List*)newList();
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 1;
		whereCondition->list = $2;
		lappend(list, whereCondition);
		$$ = list;
	}
	| simple_where_list AND '(' simple_where_list ')'
	{
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 1;
		whereCondition->list = $4;
		lappend($1, whereCondition);
		$$ = $1;
	}
	| simple_where_list OR '(' simple_where_list ')'
	{
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 2;
		whereCondition->isList = 1;
		whereCondition->list = $4;
		lappend($1, whereCondition);
		$$ = $1;
	}
	;
	
	
simple_where_single: ColId condition_op singleValue
	{
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = $2;
		whereSingle->left.isVal = 0;
		whereSingle->left.field = $1;
		whereSingle->right.isVal = 1;
		whereSingle->right.val = $3;
		$$ = whereSingle;
	}
	| singleValue condition_op singleValue
	{
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = $2;
		whereSingle->left.isVal = 1;
		whereSingle->left.val = $1;
		whereSingle->right.isVal = 1;
		whereSingle->right.val = $3;
		$$ = whereSingle;
	}
	| singleValue condition_op ColId
	{
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = $2;
		whereSingle->left.isVal = 1;
		whereSingle->left.val = $1;
		whereSingle->right.isVal = 0;
		whereSingle->right.field = $3;
		$$ = whereSingle;
	}
	;
	
SelectStmt: SELECT opt_target_list from_clause where_clause
	{
		SelectStmt* selectStmt = (SelectStmt*)makeNode(SelectStmt);
		selectStmt->optTargetList = $2;
		selectStmt->fromClause = $3;
		selectStmt->whereClause = $4;
		$$ = selectStmt;
	}
	;
	
opt_target_list: opt_target
	{
		OptTarget* optTarget = (OptTarget*)$1;
		if(optTarget != (void*)0 && (optTarget->isAll == 1 || optTarget->name != (void*)0)) {
			List* list = (List*)newList();
			lappend(list, $1);
			$$ = list;
		} else {
			$$ = (void*)0;
		}
	}
	| opt_target_list ',' opt_target
	{
		lappend($1, $3);
		$$ = $1;
	}
	;
	
opt_target: opt_target_all {$$ = $1;}
	| opt_target_normal {$$ = $1;}
	| opt_target_as {$$ = $1;}
	| opt_target_no_as {$$ = $1;}
	;
	
opt_target_all: ALL
	{
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 1;
		$$ = optTarget;
	}
	| ColId '.' ALL
	{
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 1;
		optTarget->tableAlias = $1;
		$$ = optTarget;
	}
	| {}
	;
	
opt_target_normal: ColId
	{
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 0;
		optTarget->name = $1;
		$$ = optTarget;
	}
	| ColId '.' ColId
	{
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 0;
		optTarget->tableAlias = $1;
		optTarget->name = $3;
		$$ = optTarget;
	}
	| {}
	;
	
opt_target_as: ColId AS ColId
	{
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 0;
		optTarget->name = $1;
		optTarget->alias = $3;
		$$ = optTarget;
	}
	| ColId '.' ColId AS ColId
	{
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 0;
		optTarget->tableAlias = $1;
		optTarget->name = $3;
		optTarget->alias = $5;
		$$ = optTarget;
	}
	| {}
	;

opt_target_no_as: ColId ColId
	{
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 0;
		optTarget->name = $1;
		optTarget->alias = $2;
		$$ = optTarget;
	}
	| ColId '.' ColId ColId
	{
		OptTarget* optTarget = (OptTarget*)makeNode(OptTarget);
		optTarget->isAll = 0;
		optTarget->tableAlias = $1;
		optTarget->name = $3;
		optTarget->alias = $4;
		$$ = optTarget;
	}
	| {}
	;
	
from_clause: FROM from_list {$$ = $2;}
	| {$$ = (void*)0;}
	;

from_list: ColId
	{
		FromClause* fromClause = (FromClause*)makeNode(FromClause);
		fromClause->name = $1;
		List* list = (List*)newList();
		lappend(list, fromClause);
		$$ = list;
	}
	| ColId ColId
	{
		FromClause* fromClause = (FromClause*)makeNode(FromClause);
		fromClause->name = $1;
		fromClause->alias = $2;
		List* list = (List*)newList();
		lappend(list, fromClause);
		$$ = list;
	}
	| from_list ',' ColId
	{
		FromClause* fromClause = (FromClause*)makeNode(FromClause);
		fromClause->name = $3;
		lappend($1, fromClause);
		$$ = $1;
	}
	| from_list ',' ColId ColId
	{
		FromClause* fromClause = (FromClause*)makeNode(FromClause);
		fromClause->name = $3;
		fromClause->alias = $4;
		lappend($1, fromClause);
		$$ = $1;
	}
	;
	
where_clause: WHERE where_list {$$ = $2;}
	| {$$ = (void*)0;}
	;
	
where_list: where_single
	{
		List* list = (List*)newList();
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 0;
		whereCondition->whereSingle = $1;
		lappend(list, whereCondition);
		$$ = list;
	}
	| where_list AND where_single
	{
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 0;
		whereCondition->whereSingle = $3;
		lappend($1, whereCondition);
		$$ = $1;
	}
	| where_list OR where_single
	{
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 2;
		whereCondition->isList = 0;
		whereCondition->whereSingle = $3;
		lappend($1, whereCondition);
		$$ = $1;
	}
	| where_list AND '(' where_list ')'
	{
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 1;
		whereCondition->list = $4;
		lappend($1, whereCondition);
		$$ = $1;
	}
	| where_list OR '(' where_list ')'
	{
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 2;
		whereCondition->isList = 1;
		whereCondition->list = $4;
		lappend($1, whereCondition);
		$$ = $1;
	}
	| '(' where_list ')'
	{
		List* list = (List*)newList();
		WhereCondition* whereCondition = (WhereCondition*)makeNode(WhereCondition);
		whereCondition->condition = 1;
		whereCondition->isList = 1;
		whereCondition->list = $2;
		lappend(list, whereCondition);
		$$ = list;
	}
	;

where_single: ColId condition_op singleValue
	{
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = $2;
		whereSingle->left.isVal = 0;
		whereSingle->left.field = $1;
		whereSingle->right.isVal = 1;
		whereSingle->right.val = $3;
		$$ = whereSingle;
	}
	| ColId '.' ColId condition_op singleValue
	{
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = $4;
		whereSingle->left.isVal = 0;
		whereSingle->left.tableAlias = $1;
		whereSingle->left.field = $3;
		whereSingle->right.isVal = 1;
		whereSingle->right.val = $5;
		$$ = whereSingle;
	}
	| ColId condition_op ColId
	{
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = $2;
		whereSingle->left.isVal = 0;
		whereSingle->left.field = $1;
		whereSingle->right.isVal = 0;
		whereSingle->right.field = $3;
		$$ = whereSingle;
	}
	| ColId '.' ColId condition_op ColId '.' ColId
	{
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = $4;
		whereSingle->left.isVal = 0;
		whereSingle->left.tableAlias = $1;
		whereSingle->left.field = $3;
		whereSingle->right.isVal = 0;
		whereSingle->right.tableAlias = $5;
		whereSingle->right.field = $7;
		$$ = whereSingle;
	}
	| singleValue condition_op singleValue
	{
		WhereSingle* whereSingle = (WhereSingle*)makeNode(WhereSingle);
		whereSingle->op = $2;
		whereSingle->left.isVal = 1;
		whereSingle->left.val = $1;
		whereSingle->right.isVal = 1;
		whereSingle->right.val = $3;
		$$ = whereSingle;
	}
	;
	
	
condition_op: '=' {$$ = "=";}
	| '>' {$$ = ">";}
	| '<' {$$ = "<";}
	;
	
InsertStmt: INSERT INTO table_name columnsList VALUES valuesList
	{
		InsertStmt* insertStmt = (InsertStmt*)makeNode(InsertStmt);
		insertStmt->tableNode = $3;
		insertStmt->columnsList = $4;
		insertStmt->valuesList = $6;
		$$ = insertStmt;
	}
	;
	
columnsList: '(' identList ')'
	{
		$$ = $2;
	}
	|
	{
		List* list = (List*)newList();
		$$ = list;
	}
	;

identList: ColId
	{
		List* list = (List*)newList();
		lappend(list, $1);
		$$ = list;
	}
	| identList ',' ColId
	{
		lappend($1, $3);
		$$ = $1;
	}
	;
	
valuesList: '(' multiValue ')'
	{
		List* list = (List*)newList();
		lappend(list, $2);
		$$ = list;
	}
	|valuesList ',' '(' multiValue ')'
	{
		lappend($1, $4);
		$$ = $1;
	}
	;
	
multiValue: singleValue
	{
		List* list = (List*)newList();
		lappend(list, $1);
		$$ = list;
	}
	| multiValue ',' singleValue
	{
		lappend($1, $3);
		$$ = $1;
	}
	;
	
singleValue: '\'' ColId '\'' {$$ = $2;}
	| '\'' ICONST '\'' {$$ = fnc_itoa($2);}
	| ICONST {$$ = fnc_itoa($1);}
	;

CreateStmt: CREATE TABLE table_name '(' TableElementList ')'
	{
		CreateStmt* createStmt = (CreateStmt*)makeNode(CreateStmt);
		createStmt->tableNode = $3;
		createStmt->tableElementList = $5;
		$$ = createStmt;
	}
	;
	
TableElementList: columnDef
	{
		List* list = (List*)newList();
		lappend(list, $1);
		$$ = list;
	}
	| TableElementList ',' columnDef
	{
		lappend($1, $3);
		$$ = $1;
	}
	;
	
columnDef: ColId TypeName Iconst Nullable
	{
		ColumnNode* columnNode = (ColumnNode*)makeNode(ColumnNode);
		columnNode->fieldName = $1;
		columnNode->length = calcLength($2, $3);
		columnNode->flag = $2 << 2 | $4 << 1 | flexable($2);
		$$ = columnNode;
	}
	;
	
Nullable: NOT NULLS_P {$$ = 0;}
	| {$$ = 1;}
	;
	
ColId:
	IDENT
	{
		$$ = $1;
	}
	|unreserved_keyword
	{
		$$ = $1;
	}
	|col_name_keyword
	{
		$$ = $1;
	}
	;
	
	
TypeName: CHAR_P {$$ = 1;}
	|INT_P {$$ = 3;}
	|VARCHAR_P {$$ = 4;}
	|TEXT_P {$$ = 5;}
	|BIGINT {$$ = 6;}
	;

	
table_name: IDENT
	{
		TableNode* tableNode = (TableNode*)makeNode(TableNode);
		tableNode->tableName = $1;
		$$ = tableNode;
	}
	;

Iconst: '(' ICONST ')' {$$ = $2;}
	| 	{$$ = 0;}
	;

col_name_keyword:
			  BETWEEN
			| BIGINT
			| BIT
			| BOOLEAN_P
			| CHAR_P
			| CHARACTER
			| COALESCE
			| DEC
			| DECIMAL_P
			| EXISTS
			| EXTRACT
			| FLOAT_P
			| GREATEST
			| GROUPING
			| INOUT
			| INT_P
			| INTEGER
			| INTERVAL
			| LEAST
			| NATIONAL
			| NCHAR
			| NONE
			| NULLIF
			| NUMERIC
			| OUT_P
			| OVERLAY
			| POSITION
			| PRECISION
			| REAL
			| ROW
			| SETOF
			| SMALLINT
			| SUBSTRING
			| TIME
			| TIMESTAMP
			| TREAT
			| TRIM
			| VALUES
			| VARCHAR_P
			| XMLATTRIBUTES
			| XMLCONCAT
			| XMLELEMENT
			| XMLEXISTS
			| XMLFOREST
			| XMLNAMESPACES
			| XMLPARSE
			| XMLPI
			| XMLROOT
			| XMLSERIALIZE
			| XMLTABLE
		;

unreserved_keyword:
			  ABORT_P
			| ABSOLUTE_P
			| ACCESS
			| ACTION
			| ADD_P
			| ADMIN
			| AFTER
			| AGGREGATE
			| ALSO
			| ALTER
			| ALWAYS
			| ASSERTION
			| ASSIGNMENT
			| AT
			| ATTACH
			| ATTRIBUTE
			| BACKWARD
			| BEFORE
			| BEGIN_P
			| BY
			| CACHE
			| CALL
			| CALLED
			| CASCADE
			| CASCADED
			| CATALOG_P
			| CHAIN
			| CHARACTERISTICS
			| CHECKPOINT
			| CLASS
			| CLOSE
			| CLUSTER
			| COLUMNS
			| COMMENT
			| COMMENTS
			| COMMIT
			| COMMITTED
			| CONFIGURATION
			| CONFLICT
			| CONNECTION
			| CONSTRAINTS
			| CONTENT_P
			| CONTINUE_P
			| CONVERSION_P
			| COPY
			| COST
			| CSV
			| CUBE
			| CURRENT_P
			| CURSOR
			| CYCLE
			| DATA_P
			| DATABASE
			| DAY_P
			| DEALLOCATE
			| DECLARE
			| DEFAULTS
			| DEFERRED
			| DEFINER
			| DELETE_P
			| DELIMITER
			| DELIMITERS
			| DEPENDS
			| DETACH
			| DICTIONARY
			| DISABLE_P
			| DISCARD
			| DOCUMENT_P
			| DOMAIN_P
			| DOUBLE_P
			| DROP
			| EACH
			| ENABLE_P
			| ENCODING
			| ENCRYPTED
			| ENUM_P
			| ESCAPE
			| EVENT
			| EXCLUDE
			| EXCLUDING
			| EXCLUSIVE
			| EXECUTE
			| EXPLAIN
			| EXTENSION
			| EXTERNAL
			| FAMILY
			| FILTER
			| FIRST_P
			| FOLLOWING
			| FORCE
			| FORWARD
			| FUNCTION
			| FUNCTIONS
			| GENERATED
			| GLOBAL
			| GRANTED
			| GROUPS
			| HANDLER
			| HEADER_P
			| HOLD
			| HOUR_P
			| IDENTITY_P
			| IF_P
			| IMMEDIATE
			| IMMUTABLE
			| IMPLICIT_P
			| IMPORT_P
			| INCLUDE
			| INCLUDING
			| INCREMENT
			| INDEX
			| INDEXES
			| INHERIT
			| INHERITS
			| INLINE_P
			| INPUT_P
			| INSENSITIVE
			| INSERT
			| INSTEAD
			| INVOKER
			| ISOLATION
			| KEY
			| LABEL
			| LANGUAGE
			| LARGE_P
			| LAST_P
			| LEAKPROOF
			| LEVEL
			| LISTEN
			| LOAD
			| LOCAL
			| LOCATION
			| LOCK_P
			| LOCKED
			| LOGGED
			| MAPPING
			| MATCH
			| MATERIALIZED
			| MAXVALUE
			| METHOD
			| MINUTE_P
			| MINVALUE
			| MODE
			| MONTH_P
			| MOVE
			| NAME_P
			| NAMES
			| NEW
			| NEXT
			| NO
			| NOTHING
			| NOTIFY
			| NOWAIT
			| NULLS_P
			| OBJECT_P
			| OF
			| OFF
			| OIDS
			| OLD
			| OPERATOR
			| OPTION
			| OPTIONS
			| ORDINALITY
			| OTHERS
			| OVER
			| OVERRIDING
			| OWNED
			| OWNER
			| PARALLEL
			| PARSER
			| PARTIAL
			| PARTITION
			| PASSING
			| PASSWORD
			| PLANS
			| POLICY
			| PRECEDING
			| PREPARE
			| PREPARED
			| PRESERVE
			| PRIOR
			| PRIVILEGES
			| PROCEDURAL
			| PROCEDURE
			| PROCEDURES
			| PROGRAM
			| PUBLICATION
			| QUOTE
			| RANGE
			| READ
			| REASSIGN
			| RECHECK
			| RECURSIVE
			| REF_P
			| REFERENCING
			| REFRESH
			| REINDEX
			| RELATIVE_P
			| RELEASE
			| RENAME
			| REPEATABLE
			| REPLACE
			| REPLICA
			| RESET
			| RESTART
			| RESTRICT
			| RETURNS
			| REVOKE
			| ROLE
			| ROLLBACK
			| ROLLUP
			| ROUTINE
			| ROUTINES
			| ROWS
			| RULE
			| SAVEPOINT
			| SCHEMA
			| SCHEMAS
			| SCROLL
			| SEARCH
			| SECOND_P
			| SECURITY
			| SEQUENCE
			| SEQUENCES
			| SERIALIZABLE
			| SERVER
			| SESSION
			| SET
			| SETS
			| SHARE
			| SHOW
			| SIMPLE
			| SKIP
			| SNAPSHOT
			| SQL_P
			| STABLE
			| STANDALONE_P
			| START
			| STATEMENT
			| STATISTICS
			| STDIN
			| STDOUT
			| STORAGE
			| STORED
			| STRICT_P
			| STRIP_P
			| SUBSCRIPTION
			| SUPPORT
			| SYSID
			| SYSTEM_P
			| TABLES
			| TABLESPACE
			| TEMP
			| TEMPLATE
			| TEMPORARY
			| TEXT_P
			| TIES
			| TRANSACTION
			| TRANSFORM
			| TRIGGER
			| TRUNCATE
			| TRUSTED
			| TYPE_P
			| TYPES_P
			| UNBOUNDED
			| UNCOMMITTED
			| UNENCRYPTED
			| UNKNOWN
			| UNLISTEN
			| UNLOGGED
			| UNTIL
			| UPDATE
			| VACUUM
			| VALID
			| VALIDATE
			| VALIDATOR
			| VALUE_P
			| VARYING
			| VERSION_P
			| VIEW
			| VIEWS
			| VOLATILE
			| WHITESPACE_P
			| WITHIN
			| WITHOUT
			| WORK
			| WRAPPER
			| WRITE
			| XML_P
			| YEAR_P
			| YES_P
			| ZONE
		;

reserved_keyword:
			ALL
			| ANALYSE
			| ANALYZE
			| AND
			| ANY
			| ARRAY
			| AS
			| ASC
			| ASYMMETRIC
			| BOTH
			| CASE
			| CAST
			| CHECK
			| COLLATE
			| COLUMN
			| CONSTRAINT
			| CREATE
			| CURRENT_CATALOG
			| CURRENT_DATE
			| CURRENT_ROLE
			| CURRENT_TIME
			| CURRENT_TIMESTAMP
			| CURRENT_USER
			| DEFAULT
			| DEFERRABLE
			| DESC
			| DISTINCT
			| DO
			| ELSE
			| END_P
			| EXCEPT
			| FALSE_P
			| FETCH
			| FOR
			| FOREIGN
			| FROM
			| GRANT
			| GROUP_P
			| HAVING
			| IN_P
			| INITIALLY
			| INTERSECT
			| INTO
			| LATERAL_P
			| LEADING
			| LIMIT
			| LOCALTIME
			| LOCALTIMESTAMP
			| NOT
			| NULL_P
			| OFFSET
			| ON
			| ONLY
			| OR
			| ORDER
			| PLACING
			| PRIMARY
			| REFERENCES
			| RETURNING
			| SELECT
			| SESSION_USER
			| SOME
			| SYMMETRIC
			| TABLE
			| THEN
			| TO
			| TRAILING
			| TRUE_P
			| UNION
			| UNIQUE
			| USER
			| USING
			| VARIADIC
			| WHEN
			| WHERE
			| WINDOW
			| WITH
		;
%%

int flexable(int type) {
	if(type == 4 || type == 5){
		return 1;
	}
	return 0;
}

int calcLength(int type, int length) {
	if(length > 0){
		return length;
	}
	switch(type) {
		case 1:
			length = 1;
			break;
		case 2:
			length = 2;
			break;
		case 3:
			length = 4;
			break;
		case 6:
			length = 8;
			break;
		case 4:
			length = 1;
			break;
	}
	return length;
}

char* fnc_itoa(int number) {
	int _number = number;
	int len = 0;
	for(;;) {
		len++;
		if((_number = _number / 10) == 0){
			break;
		}
	}
	_number = number;
	char* buff = malloc(len + 1);
	*(buff + len) = 0;
	for(;len > 0; len--) {
		int i = _number % 10;
		*(buff + (len - 1)) = i + 0x30;
		_number = _number / 10;
	}
	return buff;
}

void yyerror(yyscan_t yyscanner, char *str) {
	fprintf(stderr, "error:%s\n", str);
	(*((yy_extra_type **) (yyscanner)))->list = (void*)0;
}

int yywrap() {
	return 1;
}
