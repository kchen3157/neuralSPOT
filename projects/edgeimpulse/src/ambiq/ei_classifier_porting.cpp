/* Edge Impulse inferencing library
 * Copyright (c) 2021 EdgeImpulse Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "../ei_classifier_porting.h"
#if EI_PORTING_AMBIQ == 1

#include <stdarg.h>
#include <stdlib.h>
#include "ns_timer.h"
#include "ns_ambiqsuite_harness.h"
#include "ns_malloc.h"
#include <cstring>

#define EI_WEAK_FN __attribute__((weak))

extern ns_timer_config_t ei_tickTimer;

EI_WEAK_FN EI_IMPULSE_ERROR ei_run_impulse_check_canceled() {
    return EI_IMPULSE_OK;
}

/**
 * Cancelable sleep, can be triggered with signal from other thread
 */
EI_WEAK_FN EI_IMPULSE_ERROR ei_sleep(int32_t time_ms) {
    ns_delay_us(time_ms*1000);
    return EI_IMPULSE_OK;
}

uint64_t ei_read_timer_ms() {
    return ns_us_ticker_read(&ei_tickTimer) / 1000L;
}

uint64_t ei_read_timer_us() {
    return ns_us_ticker_read(&ei_tickTimer);

}

__attribute__((weak)) void ei_printf(const char *format, ...) {
    va_list myargs;
    va_start(myargs, format);
    am_util_stdio_vprintf(format, myargs);
    va_end(myargs);
}

__attribute__((weak)) void ei_printf_float(float f) {
    ei_printf("%f", f);
}

__attribute__((weak)) void *ei_malloc(size_t size) {
    void *p = ns_malloc(size);
    // ns_lp_printf("malloc 0x%x @ 0x%x\n",size,p);
    // if (p == NULL)
    //     while(1);
    return p;
}

__attribute__((weak)) void *ei_calloc(size_t nitems, size_t size) {
    void *ret = ns_malloc(nitems*size);
    memset(ret, 0, nitems*size);
    // ns_lp_printf("calloc 0x%x @ 0x%x\n",nitems*size,ret);
    // if (ret == NULL)
    //     while(1);
    return ret;
}

__attribute__((weak)) void ei_free(void *ptr) {
    // ns_lp_printf("free @ 0x%x\n", ptr);
    ns_free(ptr);
}

#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C"
#endif
__attribute__((weak)) void DebugLog(const char* s) {
    ei_printf("%s", s);
}

#endif // EI_PORTING_AMBIQ == 1
