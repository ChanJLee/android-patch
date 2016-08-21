//
// Created by chan on 16/8/18.
//

#ifndef YPATCH_BSPATCH_H
#define YPATCH_BSPATCH_H

#ifdef __cplusplus
extern "C" {
#endif

void run_patch(const char* old_file, const char* new_file, const char* patch_file);

#ifdef __cplusplus
}
#endif

#endif //YPATCH_BSPATCH_H
