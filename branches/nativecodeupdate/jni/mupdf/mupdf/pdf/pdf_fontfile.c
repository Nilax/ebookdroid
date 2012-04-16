#include "fitz-internal.h"
#include "mupdf-internal.h"

#ifdef NOCJK
#define NOCJKFONT
#endif

//#include "../generated/font_base14.h"

//#ifndef NODROIDFONT
//#include "../generated/font_droid.h"
//#endif

//#ifndef NOCJKFONT
//#include "../generated/font_cjk.h"
//#endif

unsigned char *
pdf_lookup_builtin_font(char *name, unsigned int *len)
{
/*
	if (!strcmp("Courier", name)) {
		*len = sizeof pdf_font_NimbusMonL_Regu;
		return (unsigned char*) pdf_font_NimbusMonL_Regu;
	}
	if (!strcmp("Courier-Bold", name)) {
		*len = sizeof pdf_font_NimbusMonL_Bold;
		return (unsigned char*) pdf_font_NimbusMonL_Bold;
	}
	if (!strcmp("Courier-Oblique", name)) {
		*len = sizeof pdf_font_NimbusMonL_ReguObli;
		return (unsigned char*) pdf_font_NimbusMonL_ReguObli;
	}
	if (!strcmp("Courier-BoldOblique", name)) {
		*len = sizeof pdf_font_NimbusMonL_BoldObli;
		return (unsigned char*) pdf_font_NimbusMonL_BoldObli;
	}
	if (!strcmp("Helvetica", name)) {
		*len = sizeof pdf_font_NimbusSanL_Regu;
		return (unsigned char*) pdf_font_NimbusSanL_Regu;
	}
	if (!strcmp("Helvetica-Bold", name)) {
		*len = sizeof pdf_font_NimbusSanL_Bold;
		return (unsigned char*) pdf_font_NimbusSanL_Bold;
	}
	if (!strcmp("Helvetica-Oblique", name)) {
		*len = sizeof pdf_font_NimbusSanL_ReguItal;
		return (unsigned char*) pdf_font_NimbusSanL_ReguItal;
	}
	if (!strcmp("Helvetica-BoldOblique", name)) {
		*len = sizeof pdf_font_NimbusSanL_BoldItal;
		return (unsigned char*) pdf_font_NimbusSanL_BoldItal;
	}
	if (!strcmp("Times-Roman", name)) {
		*len = sizeof pdf_font_NimbusRomNo9L_Regu;
		return (unsigned char*) pdf_font_NimbusRomNo9L_Regu;
	}
	if (!strcmp("Times-Bold", name)) {
		*len = sizeof pdf_font_NimbusRomNo9L_Medi;
		return (unsigned char*) pdf_font_NimbusRomNo9L_Medi;
	}
	if (!strcmp("Times-Italic", name)) {
		*len = sizeof pdf_font_NimbusRomNo9L_ReguItal;
		return (unsigned char*) pdf_font_NimbusRomNo9L_ReguItal;
	}
	if (!strcmp("Times-BoldItalic", name)) {
		*len = sizeof pdf_font_NimbusRomNo9L_MediItal;
		return (unsigned char*) pdf_font_NimbusRomNo9L_MediItal;
	}
	if (!strcmp("Symbol", name)) {
		*len = sizeof pdf_font_StandardSymL;
		return (unsigned char*) pdf_font_StandardSymL;
	}
	if (!strcmp("ZapfDingbats", name)) {
		*len = sizeof pdf_font_Dingbats;
		return (unsigned char*) pdf_font_Dingbats;
	}
	*len = 0;
	return NULL;
*/

	if (!strcmp("Courier", name)) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSansMono.ttf";
	}
	if (!strcmp("Courier-Bold", name)) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSansMono.ttf";
	}
	if (!strcmp("Courier-Oblique", name)) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSansMono.ttf";
	}
	if (!strcmp("Courier-BoldOblique", name)) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSansMono.ttf";
	}
	if (!strcmp("Helvetica", name)) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSans.ttf";
	}
	if (!strcmp("Helvetica-Bold", name)) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSans-Bold.ttf";
	}
	if (!strcmp("Helvetica-Oblique", name)) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSans.ttf";
	}
	if (!strcmp("Helvetica-BoldOblique", name)) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSans.ttf";
	}
	if (!strcmp("Times-Roman", name)) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSerif-Regular.ttf";
	}
	if (!strcmp("Times-Bold", name)) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSerif-Bold.ttf";
	}
	if (!strcmp("Times-Italic", name)) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSerif-Italic.ttf";
	}
	if (!strcmp("Times-BoldItalic", name)) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSerif-BoldItalic.ttf";
	}
	if (!strcmp("Symbol", name)) {
		*len = 0;
		return (unsigned char*) "/sdcard/.org.ebookdroid/StandardSymL.cff";
	}
	if (!strcmp("ZapfDingbats", name)) {
		*len = 0;
		return (unsigned char*) "/sdcard/.org.ebookdroid/Dingbats.cff";
	}
	*len = 0;
	return NULL;
}

unsigned char *
pdf_lookup_substitute_font(int mono, int serif, int bold, int italic, unsigned int *len)
{
/*
#ifdef NODROIDFONT
	if (mono) {
		if (bold) {
			if (italic) return pdf_lookup_builtin_font("Courier-BoldOblique", len);
			else return pdf_lookup_builtin_font("Courier-Bold", len);
		} else {
			if (italic) return pdf_lookup_builtin_font("Courier-Oblique", len);
			else return pdf_lookup_builtin_font("Courier", len);
		}
	} else if (serif) {
		if (bold) {
			if (italic) return pdf_lookup_builtin_font("Times-BoldItalic", len);
			else return pdf_lookup_builtin_font("Times-Bold", len);
		} else {
			if (italic) return pdf_lookup_builtin_font("Times-Italic", len);
			else return pdf_lookup_builtin_font("Times-Roman", len);
		}
	} else {
		if (bold) {
			if (italic) return pdf_lookup_builtin_font("Helvetica-BoldOblique", len);
			else return pdf_lookup_builtin_font("Helvetica-Bold", len);
		} else {
			if (italic) return pdf_lookup_builtin_font("Helvetica-Oblique", len);
			else return pdf_lookup_builtin_font("Helvetica", len);
		}
	}
#else
	if (mono) {
		*len = sizeof pdf_font_DroidSansMono;
		return (unsigned char*) pdf_font_DroidSansMono;
	} else {
		*len = sizeof pdf_font_DroidSans;
		return (unsigned char*) pdf_font_DroidSans;
	}
#endif
*/
	if (mono) {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSansMono.ttf";
	} else {
		*len = 0;
		return (unsigned char*) "/system/fonts/DroidSans.ttf";
	}

}

unsigned char *
pdf_lookup_substitute_cjk_font(int ros, int serif, unsigned int *len)
{
/*
#ifndef NOCJKFONT
	*len = sizeof pdf_font_DroidSansFallback;
	return (unsigned char*) pdf_font_DroidSansFallback;
#else
	*len = 0;
	return NULL;
#endif
*/
	*len = 0;
	return (unsigned char*) "/system/fonts/DroidSansFallback.ttf";
}
