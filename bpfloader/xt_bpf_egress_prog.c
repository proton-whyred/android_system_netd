/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <linux/bpf.h>
#include "bpf_kern.h"

ELF_SEC(BPF_PROG_SEC_NAME)
int xt_bpf_egress_prog(struct __sk_buff* skb) {
    uint32_t key = skb->ifindex;
    bpf_update_stats(skb, IFACE_STATS_MAP, BPF_EGRESS, &key);
    return BPF_PASS;
}
