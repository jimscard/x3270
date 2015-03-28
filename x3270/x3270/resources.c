/*
 * Copyright (c) 1993-2015 Paul Mattes.
 * Copyright (c) 1990, Jeff Sparkes.
 * Copyright (c) 1989, Georgia Tech Research Corporation (GTRC), Atlanta,
 *  GA 30332.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the names of Paul Mattes, Jeff Sparkes, GTRC nor their
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY PAUL MATTES, JEFF SPARKES AND GTRC "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL PAUL MATTES, JEFF SPARKES OR
 * GTRC BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *	resources.c
 *		Resource definitions for x3270.
 */

#include "globals.h"
#include "appres.h"
#include "resources.h"
#include "xappres.h"

#include <X11/StringDefs.h>

#include "resourcesc.h"

#define offset(field)		XtOffset(AppResptr, field)
XtResource resources[] = {
    { ResSaveLines, ClsSaveLines, XtRInt, sizeof(int),
      offset(interactive.save_lines), XtRString, "4096" },
    { ResUnlockDelayMs, ClsUnlockDelayMs, XtRInt, sizeof(int),
      offset(unlock_delay_ms), XtRString, "350" },
    { ResScriptPort, ClsScriptPort, XtRInt, sizeof(int),
      offset(script_port), XtRString, "0" },
    { ResHttpd, ClsHttpd, XtRString, sizeof(String),
      offset(httpd_port), XtRString, 0 },
    { ResLoginMacro, ClsLoginMacro, XtRString, sizeof(String),
      offset(login_macro), XtRString, 0 },
    { ResOversize, ClsOversize, XtRString, sizeof(char *),
      offset(oversize), XtRString, 0 },
    { ResConfDir, ClsConfDir, XtRString, sizeof(char *),
      offset(conf_dir), XtRString, LIBX3270DIR },
    { ResModel, ClsModel, XtRString, sizeof(char *),
      offset(model), XtRString,
#if defined(RESTRICT_3279) /*[*/
      "3279-3-E"
#else /*][*/
      "3279-4-E"
#endif /*]*/
      },
    { ResKeymap, ClsKeymap, XtRString, sizeof(char *),
      offset(interactive.key_map), XtRString, 0 },
    { ResComposeMap, ClsComposeMap, XtRString, sizeof(char *),
      offset(interactive.compose_map), XtRString, "latin1" },
    { ResHostsFile, ClsHostsFile, XtRString, sizeof(char *),
      offset(hostsfile), XtRString, 0 },
    { ResPort, ClsPort, XtRString, sizeof(char *),
      offset(port), XtRString, "telnet" },
    { ResCharset, ClsCharset, XtRString, sizeof(char *),
      offset(charset), XtRString, "bracket" },
    { ResSbcsCgcsgid, ClsSbcsCgcsgid, XtRString, sizeof(char *),
      offset(sbcs_cgcsgid), XtRString, 0 },
    { ResTermName, ClsTermName, XtRString, sizeof(char *),
      offset(termname), XtRString, 0 },
    { ResDevName, ClsDevName, XtRString, sizeof(char *),
      offset(devname), XtRString, "x3270" },
    { ResUser, ClsUser, XtRString, sizeof(char *),
      offset(user), XtRString, 0 },
    { ResMacros, ClsMacros, XtRString, sizeof(char *),
      offset(macros), XtRString, 0 },
    { ResTraceDir, ClsTraceDir, XtRString, sizeof(char *),
      offset(trace_dir), XtRString, "/tmp" },
    { ResTraceFile, ClsTraceFile, XtRString, sizeof(char *),
      offset(trace_file), XtRString, 0 },
    { ResTraceFileSize, ClsTraceFileSize, XtRString, sizeof(char *),
      offset(trace_file_size), XtRString, 0 },
    { ResScreenTraceFile, ClsScreenTraceFile, XtRString, sizeof(char *),
      offset(screentrace_file), XtRString, 0 },
    { ResDftBufferSize, ClsDftBufferSize, XtRInt, sizeof(int),
      offset(dft_buffer_size), XtRString, "4096" },
    { ResConnectFileName, ClsConnectFileName, XtRString, sizeof(String),
      offset(connectfile_name), XtRString, "~/.x3270connect" },
    { ResIdleCommand, ClsIdleCommand, XtRString, sizeof(String),
      offset(idle_command), XtRString, 0 },
    { ResIdleTimeout, ClsIdleTimeout, XtRString, sizeof(String),
      offset(idle_timeout), XtRString, 0 },
    { ResProxy, ClsProxy, XtRString, sizeof(String),
      offset(proxy), XtRString, 0 },
    { ResHostname, ClsHostname, XtRString, sizeof(String),
      offset(hostname), XtRString, 0 },
    { ResMaxRecent, ClsMaxRecent, XtRInt, sizeof(int),
      offset(max_recent), XtRString, "5" },
    { ResSuppressActions, ClsSuppressActions, XtRString, sizeof(String),
      offset(suppress_actions), XtRString, 0 },


    { ResErase, ClsErase, XtRString, sizeof(char *),
      offset(linemode.erase), XtRString, "^?" },
    { ResKill, ClsKill, XtRString, sizeof(char *),
      offset(linemode.kill), XtRString, "^U" },
    { ResWerase, ClsWerase, XtRString, sizeof(char *),
      offset(linemode.werase), XtRString, "^W" },
    { ResRprnt, ClsRprnt, XtRString, sizeof(char *),
      offset(linemode.rprnt), XtRString, "^R" },
    { ResLnext, ClsLnext, XtRString, sizeof(char *),
      offset(linemode.lnext), XtRString, "^V" },
    { ResIntr, ClsIntr, XtRString, sizeof(char *),
      offset(linemode.intr), XtRString, "^C" },
    { ResQuit, ClsQuit, XtRString, sizeof(char *),
      offset(linemode.quit), XtRString, "^\\" },
    { ResEof, ClsEof, XtRString, sizeof(char *),
      offset(linemode.eof), XtRString, "^D" },

    { ResPrinterLu, ClsPrinterLu, XtRString, sizeof(char *),
      offset(interactive.printer_lu), XtRString, 0 },
    { ResDbcsCgcsgid, ClsDbcsCgcsgid, XtRString, sizeof(char *),
      offset(dbcs_cgcsgid), XtRString, 0 },
#if defined(HAVE_LIBSSL) /*[*/
    { ResAcceptHostname, ClsAcceptHostname, XtRString, sizeof(char *),
      offset(ssl.accept_hostname), XtRString, 0 },
    { ResCaDir, ClsCaDir, XtRString, sizeof(char *),
      offset(ssl.ca_dir), XtRString, 0 },
    { ResCaFile, ClsCaFile, XtRString, sizeof(char *),
      offset(ssl.ca_file), XtRString, 0 },
    { ResCertFile, ClsCertFile, XtRString, sizeof(char *),
      offset(ssl.cert_file), XtRString, 0 },
    { ResCertFileType, ClsCertFileType, XtRString, sizeof(char *),
      offset(ssl.cert_file_type), XtRString, 0 },
    { ResChainFile, ClsChainFile, XtRString, sizeof(char *),
      offset(ssl.chain_file), XtRString, 0 },
    { ResKeyFile, ClsKeyFile, XtRString, sizeof(char *),
      offset(ssl.key_file), XtRString, 0 },
    { ResKeyFileType, ClsKeyFileType, XtRString, sizeof(char *),
      offset(ssl.key_file_type), XtRString, 0 },
    { ResKeyPasswd, ClsKeyPasswd, XtRString, sizeof(char *),
      offset(ssl.key_passwd), XtRString, 0 },
#endif /*]*/

    { ResFtCr, ClsFtCr, XtRString, sizeof(char *),
      offset(ft.cr), XtRString, 0 },
    { ResFtDirection, ClsFtDirection, XtRString, sizeof(char *),
      offset(ft.direction), XtRString, 0 },
    { ResFtHost, ClsFtHost, XtRString, sizeof(char *),
      offset(ft.host), XtRString, 0 },
    { ResFtHostFile, ClsFtHostFile, XtRString, sizeof(char *),
      offset(ft.host_file), XtRString, 0 },
    { ResFtLocalFile, ClsFtLocalFile, XtRString, sizeof(char *),
      offset(ft.local_file), XtRString, 0 },
    { ResFtMode, ClsFtMode, XtRString, sizeof(char *),
      offset(ft.mode), XtRString, 0 },
};
#undef offset

Cardinal num_resources = XtNumber(resources);

#define offset(field)	XtOffset(xappresptr_t, field)
#define boffset(field)	XtOffset(xappresptr_t, bools.field)
#define btoffset(index)	boffset(toggle[index])
XtResource xresources[] = {
    { XtNforeground, XtCForeground, XtRPixel, sizeof(Pixel),
      offset(foreground), XtRString, "XtDefaultForeground" },
    { XtNbackground, XtCBackground, XtRPixel, sizeof(Pixel),
      offset(background), XtRString, "XtDefaultBackground" },
    { ResNormalCursor, ClsNormalCursor, XtRCursor, sizeof(Cursor),
      offset(normal_mcursor), XtRString, "top_left_arrow" },
    { ResWaitCursor, ClsWaitCursor, XtRCursor, sizeof(Cursor),
      offset(wait_mcursor), XtRString, "watch" },
    { ResLockedCursor, ClsLockedCursor, XtRCursor, sizeof(Cursor),
      offset(locked_mcursor), XtRString, "X_cursor" },

    { ResColorBackground, ClsColorBackground, XtRString, sizeof(String),
      offset(colorbg_name), XtRString, "black" },
    { ResSelectBackground, ClsSelectBackground, XtRString, sizeof(String),
      offset(selbg_name), XtRString, "dim gray" },
    { ResNormalColor, ClsNormalColor, XtRString, sizeof(String),
      offset(normal_name), XtRString, "green" },
    { ResInputColor, ClsInputColor, XtRString, sizeof(String),
      offset(select_name), XtRString, "green" },
    { ResBoldColor, ClsBoldColor, XtRString, sizeof(String),
      offset(bold_name), XtRString, "green" },
    { ResCursorColor, ClsCursorColor, XtRString, sizeof(String),
      offset(cursor_color_name), XtRString, "red" },
    { ResKeypad, ClsKeypad, XtRString, sizeof(String),
      offset(keypad), XtRString, KpRight },
    { ResKeypadOn, ClsKeypadOn, XtRBoolean, sizeof(Boolean),
      offset(keypad_on), XtRString, ResFalse },
    { ResAplCircledAlpha, ClsAplCircledAlpha, XtRBoolean, sizeof(Boolean),
      offset(apl_circled_alpha), XtRString, ResFalse },
    { ResInvertKeypadShift, ClsInvertKeypadShift, XtRBoolean, sizeof(Boolean),
      offset(invert_kpshift), XtRString, ResFalse },
    { ResActiveIcon, ClsActiveIcon, XtRBoolean, sizeof(Boolean),
      offset(active_icon), XtRString, ResFalse },
    { ResLabelIcon, ClsLabelIcon, XtRBoolean, sizeof(Boolean),
      offset(label_icon), XtRString, ResFalse },
    { ResKeypadBackground, ClsKeypadBackground, XtRString, sizeof(String),
      offset(keypadbg_name), XtRString, "grey70" },
    { ResEmulatorFont, ClsEmulatorFont, XtRString, sizeof(char *),
      offset(efontname), XtRString, 0 },
    { ResUseCursorColor, ClsUseCursorColor, XtRBoolean, sizeof(Boolean),
      offset(use_cursor_color), XtRString, ResFalse },
    { ResVisualSelect, ClsVisualSelect, XtRBoolean, sizeof(Boolean),
      offset(visual_select), XtRString, ResFalse },
    { ResSuppressHost, ClsSuppressHost, XtRBoolean, sizeof(Boolean),
      offset(suppress_host), XtRString, ResFalse },
    { ResSuppressFontMenu, ClsSuppressFontMenu, XtRBoolean, sizeof(Boolean),
      offset(suppress_font_menu), XtRString, ResFalse },
    { ResAllowResize, ClsAllowResize, XtRBoolean, sizeof(Boolean),
      offset(allow_resize), XtRString, ResTrue },
    { ResNoOther, ClsNoOther, XtRBoolean, sizeof(Boolean),
      offset(no_other), XtRString, ResFalse },
    { ResBellVolume, ClsBellVolume, XtRInt, sizeof(int),
      offset(bell_volume), XtRString, "0" },
    { ResCharClass, ClsCharClass, XtRString, sizeof(char *),
      offset(char_class), XtRString, 0 },
    { ResModifiedSelColor, ClsModifiedSelColor, XtRInt, sizeof(int),
      offset(modified_sel_color), XtRString, "10" },
    { ResVisualSelectColor, ClsVisualSelectColor, XtRInt, sizeof(int),
      offset(visual_select_color), XtRString, "6" },
    { ResIconFont, ClsIconFont, XtRString, sizeof(char *),
      offset(icon_font), XtRString, "nil2" },
    { ResIconLabelFont, ClsIconLabelFont, XtRString, sizeof(char *),
      offset(icon_label_font), XtRString, "8x13" },
    { ResFixedSize, ClsFixedSize, XtRString, sizeof(char *),
      offset(fixed_size), XtRString, 0 },
    { ResColorScheme, ClsColorScheme, XtRString, sizeof(String),
      offset(color_scheme), XtRString, "default" },
    { ResInputMethod, ClsInputMethod, XtRString, sizeof(char *),
      offset(input_method), XtRString, 0 },
    { ResPreeditType, ClsPreeditType, XtRString, sizeof(char *),
      offset(preedit_type), XtRString, PT_OVER_THE_SPOT "+1" },

#if defined(USE_APP_DEFAULTS) /*[*/
    { ResAdVersion, ClsAdVersion, XtRString, sizeof(char *),
      offset(ad_version), XtRString, 0 },
#endif /*]*/

    { ResMono, ClsMono, XtRBoolean, sizeof(Boolean),
      boffset(interactive.mono), XtRString, ResFalse },
    { ResExtended, ClsExtended, XtRBoolean, sizeof(Boolean),
      boffset(extended), XtRString, ResTrue },
    { ResM3279, ClsM3279, XtRBoolean, sizeof(Boolean),
      boffset(m3279), XtRString, ResTrue },
    { ResMenuBar, ClsMenuBar, XtRBoolean, sizeof(Boolean),
      boffset(interactive.menubar), XtRString, ResTrue },
    { ResVisualBell, ClsVisualBell, XtRBoolean, sizeof(Boolean),
      boffset(interactive.visual_bell), XtRString, ResFalse },
    { ResAplMode, ClsAplMode, XtRBoolean, sizeof(Boolean),
      boffset(apl_mode), XtRString, ResFalse },
    { ResOnce, ClsOnce, XtRBoolean, sizeof(Boolean),
      boffset(once), XtRString, ResFalse },
    { ResScripted, ClsScripted, XtRBoolean, sizeof(Boolean),
      boffset(scripted), XtRString, ResFalse },
    { ResModifiedSel, ClsModifiedSel, XtRBoolean, sizeof(Boolean),
      boffset(modified_sel), XtRString, ResFalse },
    { ResUnlockDelay, ClsUnlockDelay, XtRBoolean, sizeof(Boolean),
      boffset(unlock_delay), XtRString, ResTrue },
    { ResBindLimit, ClsBindLimit, XtRBoolean, sizeof(Boolean),
      boffset(bind_limit), XtRString, ResTrue },
    { ResNewEnviron, ClsNewEnviron, XtRBoolean, sizeof(Boolean),
      boffset(new_environ), XtRString, ResTrue },
    { ResSocket, ClsSocket, XtRBoolean, sizeof(Boolean),
      boffset(socket), XtRString, ResFalse },
    { ResReconnect, ClsReconnect, XtRBoolean, sizeof(Boolean),
      boffset(interactive.reconnect), XtRString, ResFalse },
    { ResDoConfirms, ClsDoConfirms, XtRBoolean, sizeof(Boolean),
      boffset(interactive.do_confirms), XtRString, ResTrue },
    { ResNumericLock, ClsNumericLock, XtRBoolean, sizeof(Boolean),
      boffset(numeric_lock), XtRString, ResFalse },
    { ResSecure, ClsSecure, XtRBoolean, sizeof(Boolean),
      boffset(secure), XtRString, ResFalse },
    { ResOerrLock, ClsOerrLock, XtRBoolean, sizeof(Boolean),
      boffset(oerr_lock), XtRString, ResTrue },
    { ResTypeahead, ClsTypeahead, XtRBoolean, sizeof(Boolean),
      boffset(typeahead), XtRString, ResTrue },
    { ResDebugTracing, ClsDebugTracing, XtRBoolean, sizeof(Boolean),
      boffset(debug_tracing), XtRString, ResTrue },
    { ResDisconnectClear, ClsDisconnectClear, XtRBoolean, sizeof(Boolean),
      boffset(disconnect_clear), XtRString, ResFalse },
    { ResHighlightBold, ClsHighlightBold, XtRBoolean, sizeof(Boolean),
      boffset(highlight_bold), XtRString, ResFalse },
    { ResColor8, ClsColor8, XtRBoolean, sizeof(Boolean),
      boffset(color8), XtRString, ResFalse },
    { ResBsdTm, ClsBsdTm, XtRBoolean, sizeof(Boolean),
      boffset(bsd_tm), XtRString, ResFalse },
    { ResTraceMonitor, ClsTraceMonitor, XtRBoolean, sizeof(Boolean),
      boffset(trace_monitor), XtRString, ResTrue },
    { ResIdleCommandEnabled, ClsIdleCommandEnabled, XtRBoolean, sizeof(Boolean),
      boffset(idle_command_enabled), XtRString, ResFalse },
    { ResNvtMode, ClsNvtMode, XtRBoolean, sizeof(Boolean),
      boffset(nvt_mode), XtRString, ResFalse },

    { ResMonoCase, ClsMonoCase, XtRBoolean, sizeof(Boolean),
      btoffset(MONOCASE), XtRString, ResFalse },
    { ResAltCursor, ClsAltCursor, XtRBoolean, sizeof(Boolean),
      btoffset(ALT_CURSOR), XtRString, ResFalse },
    { ResCursorBlink, ClsCursorBlink, XtRBoolean, sizeof(Boolean),
      btoffset(CURSOR_BLINK), XtRString, ResFalse },
    { ResShowTiming, ClsShowTiming, XtRBoolean, sizeof(Boolean),
      btoffset(SHOW_TIMING), XtRString, ResFalse },
    { ResCursorPos, ClsCursorPos, XtRBoolean, sizeof(Boolean),
      btoffset(CURSOR_POS), XtRString, ResTrue },
    { ResTrace, ClsTrace, XtRBoolean, sizeof(Boolean),
      btoffset(TRACING), XtRString, ResFalse },
    { ResDsTrace, ClsDsTrace, XtRBoolean, sizeof(Boolean),
      boffset(dsTrace_bc), XtRString, ResFalse },
    { ResEventTrace, ClsEventTrace, XtRBoolean, sizeof(Boolean),
      boffset(eventTrace_bc), XtRString, ResFalse },
    { ResScrollBar, ClsScrollBar, XtRBoolean, sizeof(Boolean),
      btoffset(SCROLL_BAR), XtRString, ResTrue },
    { ResLineWrap, ClsLineWrap, XtRBoolean, sizeof(Boolean),
      btoffset(LINE_WRAP), XtRString, ResTrue },
    { ResBlankFill, ClsBlankFill, XtRBoolean, sizeof(Boolean),
      btoffset(BLANK_FILL), XtRString, ResFalse },
    { ResScreenTrace, ClsScreenTrace, XtRBoolean, sizeof(Boolean),
      btoffset(SCREEN_TRACE), XtRString, ResFalse },
    { ResMarginedPaste, ClsMarginedPaste, XtRBoolean, sizeof(Boolean),
      btoffset(MARGINED_PASTE), XtRString, ResFalse },
    { ResRectangleSelect, ClsRectangleSelect, XtRBoolean, sizeof(Boolean),
      btoffset(RECTANGLE_SELECT), XtRString, ResFalse },
    { ResCrosshair, ClsCrosshair, XtRBoolean, sizeof(Boolean),
      btoffset(CROSSHAIR), XtRString, ResFalse },
    { ResVisibleControl, ClsVisibleControl, XtRBoolean, sizeof(Boolean),
      btoffset(VISIBLE_CONTROL), XtRString, ResFalse },
    { ResAidWait, ClsAidWait, XtRBoolean, sizeof(Boolean),
      btoffset(AID_WAIT), XtRString, ResTrue },
    { ResOverlayPaste, ClsOverlayPaste, XtRBoolean, sizeof(Boolean),
      btoffset(OVERLAY_PASTE), XtRString, ResFalse },

    { ResIcrnl, ClsIcrnl, XtRBoolean, sizeof(Boolean),
      boffset(linemode.icrnl), XtRString, ResTrue },
    { ResInlcr, ClsInlcr, XtRBoolean, sizeof(Boolean),
      boffset(linemode.inlcr), XtRString, ResFalse },
    { ResOnlcr, ClsOnlcr, XtRBoolean, sizeof(Boolean),
      boffset(linemode.onlcr), XtRString, ResTrue },

    { ResSelfSignedOk, ClsSelfSignedOk, XtRBoolean, sizeof(Boolean),
      boffset(ssl.self_signed_ok), XtRString, ResFalse },
    { ResTls, ClsTls, XtRBoolean, sizeof(Boolean),
      boffset(ssl.tls), XtRString, ResTrue },
    { ResVerifyHostCert, ClsVerifyHostCert, XtRBoolean, sizeof(Boolean),
      boffset(ssl.verify_host_cert), XtRString, ResFalse },
};

Cardinal num_xresources = XtNumber(xresources);
