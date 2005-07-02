#include <stdio.h>
#include <librcd.h>

#include "internal.h"
#include "rccconfig.h"

static rcc_charset_id rcc_autoengine_russian(rcc_engine_context ctx, const char *buf, int len) {
    return (rcc_charset_id)rcdGetRussianCharset(buf,len);
}

rcc_language_alias rcc_default_aliases[] = {
    { "cs_SK", "sk" },
    { "ru_UA", "uk" },
    { NULL, NULL}
};

const char rcc_engine_nonconfigured[] = "NonConfigured";

rcc_engine rcc_default_engine = {
    "Off", NULL, NULL, NULL, {NULL}
};

rcc_engine rcc_russian_engine = {
    "Russian", NULL, NULL, &rcc_autoengine_russian, {"CP1251","KOI8-R","UTF-8","IBM866", NULL}
};

rcc_language rcc_default_languages[] = {
{"default", {"Default", NULL}, {
    &rcc_default_engine,
    NULL
}},
{"off", {"Default", NULL}, {
    &rcc_default_engine,
    NULL
}},
{"ru", {"Default","KOI8-R","CP1251","UTF-8","IBM866","MACCYRILLIC","ISO8859-5", NULL}, {
    &rcc_russian_engine,
    &rcc_default_engine,
    NULL
}},
{"uk", {"Default","KOI8-U","CP1251","UTF-8","IBM855","MACCYRILLIC","ISO8859-5","CP1125", NULL}, {
    &rcc_russian_engine,
    &rcc_default_engine,
    NULL
}},
{"be", {"Default", "UTF-8", "CP1251", "IBM866", "ISO-8859-5", "KOI8-UNI", "maccyr" "IBM855", NULL},{
    &rcc_default_engine,
    NULL
}},
{"bg", {"Default", "UTF-8", "CP1251", "ISO-8859-5", "IBM855", "maccyr", "ECMA-113", NULL},{
    &rcc_default_engine,
    NULL
}},
{"cz", {"Default", "UTF-8", "ISO-8859-2", "CP1250", "IBM852", "KEYBCS2", "macce", "KOI-8_CS_2", "CORK", NULL},{
    &rcc_default_engine,
    NULL
}},
{"es", {"Default", "UTF-8", "ISO-8859-4", "CP1257", "IBM775", "ISO-8859-13", "macce", "baltic", NULL},{
    &rcc_default_engine,
    NULL
}},
{"hr", {"Default", "UTF-8", "CP1250", "ISO-8859-2", "IBM852", "macce", "CORK", NULL},{
    &rcc_default_engine,
    NULL
}},
{"hu", {"Default", "UTF-8", "ISO-8859-2", "CP1250", "IBM852", "macce", "CORK", NULL},{
    &rcc_default_engine,
    NULL
}},
{"lt", {"Default", "UTF-8", "CP1257", "ISO-8859-4", "IBM775", "ISO-8859-13", "macce", "baltic", NULL},{
    &rcc_default_engine,
    NULL
}},
{"lv", {"Default", "UTF-8", "CP1257", "ISO-8859-4", "IBM775", "ISO-8859-13", "macce", "baltic", NULL},{
    &rcc_default_engine,
    NULL
}},
{"pl", {"Default", "UTF-8", "ISO-8859-2", "CP1250", "IBM852", "macce", "ISO-8859-13", "ISO-8859-16", "baltic", "CORK", NULL},{
    &rcc_default_engine,
    NULL
}},
{"sk", {"Default", "UTF-8", "CP1250", "ISO-8859-2", "IBM852", "KEYBCS2", "macce", "KOI-8_CS_2", "CORK", NULL},{
    &rcc_default_engine,
    NULL
}},
{"sl", {"Default", "UTF-8", "ISO-8859-2", "CP1250", "IBM852", "macce", "CORK", NULL},{
    &rcc_default_engine,
    NULL
}},
{"zh", {"Default", "UTF-8", "GB2312", "GBK", "GB18030", "BIG5", NULL},{
    &rcc_default_engine,
    NULL
}},
{NULL}
};

rcc_language_name rcc_default_language_names[RCC_MAX_LANGUAGES+1] = {
{"default", "Autodetect"},
{"off", "Dissable"},
{"ru","Russian"},
{"uk","Ukrainian"}, 
{"be","Belarussian"},
{"bg","Bulgarian"},
{"cz","Czech"},
{"es","Estonian"},
{"hr","Croatian"},
{"hu","Hungarian"},
{"lt","Lithuanian"},
{"lv","Latvian"},
{"pl","Polish"},
{"sk","Slovak"},
{"sl","Slovenian"},
{"zh","Chinese"},
{NULL, NULL}
};

rcc_option_name rcc_default_option_names[] = {
    { RCC_LEARNING_MODE, "Learning Mode" },
    { RCC_AUTODETECT_FS_TITLES, "Autodetect FS Encoding" },
    { RCC_AUTODETECT_FS_NAMES, "Autodetect File Names" },
    { RCC_MAX_OPTIONS, NULL}
};
