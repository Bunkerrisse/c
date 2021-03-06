/*
 * v1beta1_daemon_set_spec.h
 *
 * DaemonSetSpec is the specification of a daemon set.
 */

#ifndef _v1beta1_daemon_set_spec_H_
#define _v1beta1_daemon_set_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"
#include "v1beta1_daemon_set_update_strategy.h"



typedef struct v1beta1_daemon_set_spec_t {
    int min_ready_seconds; //numeric
    int revision_history_limit; //numeric
    struct v1_label_selector_t *selector; //model
    struct v1_pod_template_spec_t *template; //model
    long template_generation; //numeric
    struct v1beta1_daemon_set_update_strategy_t *update_strategy; //model

} v1beta1_daemon_set_spec_t;

v1beta1_daemon_set_spec_t *v1beta1_daemon_set_spec_create(
    int min_ready_seconds,
    int revision_history_limit,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *template,
    long template_generation,
    v1beta1_daemon_set_update_strategy_t *update_strategy
);

void v1beta1_daemon_set_spec_free(v1beta1_daemon_set_spec_t *v1beta1_daemon_set_spec);

v1beta1_daemon_set_spec_t *v1beta1_daemon_set_spec_parseFromJSON(cJSON *v1beta1_daemon_set_specJSON);

cJSON *v1beta1_daemon_set_spec_convertToJSON(v1beta1_daemon_set_spec_t *v1beta1_daemon_set_spec);

#endif /* _v1beta1_daemon_set_spec_H_ */

