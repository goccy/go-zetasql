    KW_NOT_EQUALS_C_STYLE = 265,   // "!="
    KW_NOT_EQUALS_SQL_STYLE = 266, // "<>"
    KW_LESS_EQUALS = 267,          // "<="
    KW_GREATER_EQUALS = 268,       // ">="
    KW_DOUBLE_AT = 269,            // "@@"
    KW_CONCAT_OP = 270,            // "||"
    KW_DOT_STAR = 271,             // ".*"
    KW_OPEN_HINT = 272,            // "@{"
    KW_OPEN_INTEGER_HINT = 273,    // "@n"
    KW_SHIFT_LEFT = 274,           // "<<"
    KW_SHIFT_RIGHT = 275,          // ">>"
    KW_NAMED_ARGUMENT_ASSIGNMENT = 276, // "=>"
    KW_LAMBDA_ARROW = 277,         // "->"
    KW_ALL = 282,                  // "ALL"
    KW_AND = 283,                  // "AND"
    KW_AND_FOR_BETWEEN = 284,      // "AND for BETWEEN"
    KW_ANY = 285,                  // "ANY"
    KW_ARRAY = 286,                // "ARRAY"
    KW_AS = 287,                   // "AS"
    KW_ASC = 288,                  // "ASC"
    KW_ASSERT_ROWS_MODIFIED = 289, // "ASSERT_ROWS_MODIFIED"
    KW_AT = 290,                   // "AT"
    KW_BETWEEN = 291,              // "BETWEEN"
    KW_BY = 292,                   // "BY"
    KW_CASE = 293,                 // "CASE"
    KW_CAST = 294,                 // "CAST"
    KW_COLLATE = 295,              // "COLLATE"
    KW_CREATE = 296,               // "CREATE"
    KW_CROSS = 297,                // "CROSS"
    KW_CURRENT = 298,              // "CURRENT"
    KW_DEFAULT = 299,              // "DEFAULT"
    KW_DEFINE = 300,               // "DEFINE"
    KW_DESC = 301,                 // "DESC"
    KW_DISTINCT = 302,             // "DISTINCT"
    KW_ELSE = 303,                 // "ELSE"
    KW_END = 304,                  // "END"
    KW_ENUM = 305,                 // "ENUM"
    KW_EXCEPT_IN_SET_OP = 306,     // "EXCEPT in set operation"
    KW_EXCEPT = 307,               // "EXCEPT"
    KW_EXISTS = 308,               // "EXISTS"
    KW_EXTRACT = 309,              // "EXTRACT"
    KW_FALSE = 310,                // "FALSE"
    KW_FOLLOWING = 311,            // "FOLLOWING"
    KW_FROM = 312,                 // "FROM"
    KW_FULL = 313,                 // "FULL"
    KW_GROUP = 314,                // "GROUP"
    KW_GROUPING = 315,             // "GROUPING"
    KW_HASH = 316,                 // "HASH"
    KW_HAVING = 317,               // "HAVING"
    KW_IF = 318,                   // "IF"
    KW_IGNORE = 319,               // "IGNORE"
    KW_IN = 320,                   // "IN"
    KW_INNER = 321,                // "INNER"
    KW_INTERSECT = 322,            // "INTERSECT"
    KW_INTERVAL = 323,             // "INTERVAL"
    KW_INTO = 324,                 // "INTO"
    KW_IS = 325,                   // "IS"
    KW_JOIN = 326,                 // "JOIN"
    KW_LEFT = 327,                 // "LEFT"
    KW_LIKE = 328,                 // "LIKE"
    KW_LIMIT = 329,                // "LIMIT"
    KW_LOOKUP = 330,               // "LOOKUP"
    KW_MERGE = 331,                // "MERGE"
    KW_NATURAL = 332,              // "NATURAL"
    KW_NEW = 333,                  // "NEW"
    KW_NO = 334,                   // "NO"
    KW_NOT = 335,                  // "NOT"
    KW_NULL = 336,                 // "NULL"
    KW_NULLS = 337,                // "NULLS"
    KW_ON = 338,                   // "ON"
    KW_OR = 339,                   // "OR"
    KW_ORDER = 340,                // "ORDER"
    KW_OUTER = 341,                // "OUTER"
    KW_OVER = 342,                 // "OVER"
    KW_PARTITION = 343,            // "PARTITION"
    KW_PRECEDING = 344,            // "PRECEDING"
    KW_PROTO = 345,                // "PROTO"
    KW_RANGE = 346,                // "RANGE"
    KW_RECURSIVE = 347,            // "RECURSIVE"
    KW_RESPECT = 348,              // "RESPECT"
    KW_RIGHT = 349,                // "RIGHT"
    KW_ROLLUP = 350,               // "ROLLUP"
    KW_ROWS = 351,                 // "ROWS"
    KW_SELECT = 352,               // "SELECT"
    KW_SET = 353,                  // "SET"
    KW_STRUCT = 354,               // "STRUCT"
    KW_TABLESAMPLE = 355,          // "TABLESAMPLE"
    KW_THEN = 356,                 // "THEN"
    KW_TO = 357,                   // "TO"
    KW_TRUE = 358,                 // "TRUE"
    KW_UNBOUNDED = 359,            // "UNBOUNDED"
    KW_UNION = 360,                // "UNION"
    KW_USING = 361,                // "USING"
    KW_WHEN = 362,                 // "WHEN"
    KW_WHERE = 363,                // "WHERE"
    KW_WINDOW = 364,               // "WINDOW"
    KW_WITH = 365,                 // "WITH"
    KW_UNNEST = 366,               // "UNNEST"
    KW_CONTAINS = 367,             // "CONTAINS"
    KW_CUBE = 368,                 // "CUBE"
    KW_ESCAPE = 369,               // "ESCAPE"
    KW_EXCLUDE = 370,              // "EXCLUDE"
    KW_FETCH = 371,                // "FETCH"
    KW_FOR = 372,                  // "FOR"
    KW_GROUPS = 373,               // "GROUPS"
    KW_LATERAL = 374,              // "LATERAL"
    KW_OF = 375,                   // "OF"
    KW_SOME = 376,                 // "SOME"
    KW_TREAT = 377,                // "TREAT"
    KW_WITHIN = 378,               // "WITHIN"
    KW_QUALIFY_RESERVED = 379,     // KW_QUALIFY_RESERVED
    KW_NOT_SPECIAL = 380,          // "NOT_SPECIAL"
    KW_ABORT = 381,                // "ABORT"
    KW_ACCESS = 382,               // "ACCESS"
    KW_ACTION = 383,               // "ACTION"
    KW_ADD = 384,                  // "ADD"
    KW_AGGREGATE = 385,            // "AGGREGATE"
    KW_ALTER = 386,                // "ALTER"
    KW_ANONYMIZATION = 387,        // "ANONYMIZATION"
    KW_ANALYZE = 388,              // "ANALYZE"
    KW_ASSERT = 389,               // "ASSERT"
    KW_BATCH = 390,                // "BATCH"
    KW_BEGIN = 391,                // "BEGIN"
    KW_BIGDECIMAL = 392,           // "BIGDECIMAL"
    KW_BIGNUMERIC = 393,           // "BIGNUMERIC"
    KW_BREAK = 394,                // "BREAK"
    KW_CALL = 395,                 // "CALL"
    KW_CASCADE = 396,              // "CASCADE"
    KW_CHECK = 397,                // "CHECK"
    KW_CLAMPED = 398,              // "CLAMPED"
    KW_CLONE = 399,                // "CLONE"
    KW_COPY = 400,                 // "COPY"
    KW_CLUSTER = 401,              // "CLUSTER"
    KW_COLUMN = 402,               // "COLUMN"
    KW_COLUMNS = 403,              // "COLUMNS"
    KW_COMMIT = 404,               // "COMMIT"
    KW_CONNECTION = 405,           // "CONNECTION"
    KW_CONTINUE = 406,             // "CONTINUE"
    KW_CONSTANT = 407,             // "CONSTANT"
    KW_CONSTRAINT = 408,           // "CONSTRAINT"
    KW_DATA = 409,                 // "DATA"
    KW_DATABASE = 410,             // "DATABASE"
    KW_DATE = 411,                 // "DATE"
    KW_DATETIME = 412,             // "DATETIME"
    KW_DECIMAL = 413,              // "DECIMAL"
    KW_DECLARE = 414,              // "DECLARE"
    KW_DEFINER = 415,              // "DEFINER"
    KW_DELETE = 416,               // "DELETE"
    KW_DESCRIBE = 417,             // "DESCRIBE"
    KW_DESCRIPTOR = 418,           // "DESCRIPTOR"
    KW_DETERMINISTIC = 419,        // "DETERMINISTIC"
    KW_DO = 420,                   // "DO"
    KW_DROP = 421,                 // "DROP"
    KW_ENFORCED = 422,             // "ENFORCED"
    KW_ELSEIF = 423,               // "ELSEIF"
    KW_EXECUTE = 424,              // "EXECUTE"
    KW_EXPLAIN = 425,              // "EXPLAIN"
    KW_EXPORT = 426,               // "EXPORT"
    KW_EXTERNAL = 427,             // "EXTERNAL"
    KW_FILES = 428,                // "FILES"
    KW_FILTER = 429,               // "FILTER"
    KW_FILTER_FIELDS = 430,        // "FILTER_FIELDS"
    KW_FILL = 431,                 // "FILL"
    KW_FIRST = 432,                // "FIRST"
    KW_FOREIGN = 433,              // "FOREIGN"
    KW_FORMAT = 434,               // "FORMAT"
    KW_FUNCTION = 435,             // "FUNCTION"
    KW_GENERATED = 436,            // "GENERATED"
    KW_GRANT = 437,                // "GRANT"
    KW_GROUP_ROWS = 438,           // "GROUP_ROWS"
    KW_HIDDEN = 439,               // "HIDDEN"
    KW_IMMEDIATE = 440,            // "IMMEDIATE"
    KW_IMMUTABLE = 441,            // "IMMUTABLE"
    KW_IMPORT = 442,               // "IMPORT"
    KW_INCLUDE = 443,              // "INCLUDE"
    KW_INDEX = 444,                // "INDEX"
    KW_INOUT = 445,                // "INOUT"
    KW_INSERT = 446,               // "INSERT"
    KW_INVOKER = 447,              // "INVOKER"
    KW_ITERATE = 448,              // "ITERATE"
    KW_ISOLATION = 449,            // "ISOLATION"
    KW_JSON = 450,                 // "JSON"
    KW_KEY = 451,                  // "KEY"
    KW_LANGUAGE = 452,             // "LANGUAGE"
    KW_LAST = 453,                 // "LAST"
    KW_LEAVE = 454,                // "LEAVE"
    KW_LEVEL = 455,                // "LEVEL"
    KW_LOAD = 456,                 // "LOAD"
    KW_LOOP = 457,                 // "LOOP"
    KW_MATCH = 458,                // "MATCH"
    KW_MATCHED = 459,              // "MATCHED"
    KW_MATERIALIZED = 460,         // "MATERIALIZED"
    KW_MAX = 461,                  // "MAX"
    KW_MESSAGE = 462,              // "MESSAGE"
    KW_MIN = 463,                  // "MIN"
    KW_MODEL = 464,                // "MODEL"
    KW_MODULE = 465,               // "MODULE"
    KW_NUMERIC = 466,              // "NUMERIC"
    KW_OFFSET = 467,               // "OFFSET"
    KW_ONLY = 468,                 // "ONLY"
    KW_OPTIONS = 469,              // "OPTIONS"
    KW_OUT = 470,                  // "OUT"
    KW_OVERWRITE = 471,            // "OVERWRITE"
    KW_PERCENT = 472,              // "PERCENT"
    KW_PIVOT = 473,                // "PIVOT"
    KW_POLICIES = 474,             // "POLICIES"
    KW_POLICY = 475,               // "POLICY"
    KW_PRIMARY = 476,              // "PRIMARY"
    KW_PRIVATE = 477,              // "PRIVATE"
    KW_PRIVILEGE = 478,            // "PRIVILEGE"
    KW_PRIVILEGES = 479,           // "PRIVILEGES"
    KW_PROCEDURE = 480,            // "PROCEDURE"
    KW_PUBLIC = 481,               // "PUBLIC"
    KW_QUALIFY_NONRESERVED = 482,  // KW_QUALIFY_NONRESERVED
    KW_RAISE = 483,                // "RAISE"
    KW_READ = 484,                 // "READ"
    KW_REFERENCES = 485,           // "REFERENCES"
    KW_REMOTE = 486,               // "REMOTE"
    KW_REMOVE = 487,               // "REMOVE"
    KW_RENAME = 488,               // "RENAME"
    KW_REPEAT = 489,               // "REPEAT"
    KW_REPEATABLE = 490,           // "REPEATABLE"
    KW_REPLACE = 491,              // "REPLACE"
    KW_REPLACE_FIELDS = 492,       // "REPLACE_FIELDS"
    KW_RESTRICT = 493,             // "RESTRICT"
    KW_RESTRICTION = 494,          // "RESTRICTION"
    KW_RETURN = 495,               // "RETURN"
    KW_RETURNS = 496,              // "RETURNS"
    KW_REVOKE = 497,               // "REVOKE"
    KW_ROLLBACK = 498,             // "ROLLBACK"
    KW_ROW = 499,                  // "ROW"
    KW_RUN = 500,                  // "RUN"
    KW_SAFE_CAST = 501,            // "SAFE_CAST"
    KW_SCHEMA = 502,               // "SCHEMA"
    KW_SEARCH = 503,               // "SEARCH"
    KW_SECURITY = 504,             // "SECURITY"
    KW_SHOW = 505,                 // "SHOW"
    KW_SIMPLE = 506,               // "SIMPLE"
    KW_SNAPSHOT = 507,             // "SNAPSHOT"
    KW_SOURCE = 508,               // "SOURCE"
    KW_SQL = 509,                  // "SQL"
    KW_STABLE = 510,               // "STABLE"
    KW_START = 511,                // "START"
    KW_STORED = 512,               // "STORED"
    KW_STORING = 513,              // "STORING"
    KW_SYSTEM = 514,               // "SYSTEM"
    KW_SYSTEM_TIME = 515,          // "SYSTEM_TIME"
    KW_TABLE = 516,                // "TABLE"
    KW_TARGET = 517,               // "TARGET"
    KW_TRANSFORM = 518,            // "TRANSFORM"
    KW_TEMP = 519,                 // "TEMP"
    KW_TEMPORARY = 520,            // "TEMPORARY"
    KW_TIME = 521,                 // "TIME"
    KW_TIMESTAMP = 522,            // "TIMESTAMP"
    KW_TRANSACTION = 523,          // "TRANSACTION"
    KW_TRUNCATE = 524,             // "TRUNCATE"
    KW_TYPE = 525,                 // "TYPE"
    KW_UNIQUE = 526,               // "UNIQUE"
    KW_UNKNOWN = 527,              // "UNKNOWN"
    KW_UNPIVOT = 528,              // "UNPIVOT"
    KW_UNTIL = 529,                // "UNTIL"
    KW_UPDATE = 530,               // "UPDATE"
    KW_VALUE = 531,                // "VALUE"
    KW_VALUES = 532,               // "VALUES"
    KW_VOLATILE = 533,             // "VOLATILE"
    KW_VIEW = 534,                 // "VIEW"
    KW_VIEWS = 535,                // "VIEWS"
    KW_WEIGHT = 536,               // "WEIGHT"
    KW_WHILE = 537,                // "WHILE"
    KW_WRITE = 538,                // "WRITE"
    KW_ZONE = 539,                 // "ZONE"
    KW_EXCEPTION = 540,            // "EXCEPTION"
    KW_ERROR = 541,                // "ERROR"
    KW_CURRENT_DATETIME_FUNCTION = 542, // KW_CURRENT_DATETIME_FUNCTION
