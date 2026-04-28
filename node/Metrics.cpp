#include "Metrics.hpp"

namespace prometheus { namespace simpleapi { std::shared_ptr<Registry> registry_ptr; } }

static prometheus::CustomFamily<prometheus::Histogram<uint64_t>> _peer_latency_family;

namespace ZeroTier { namespace Metrics {
    prometheus::simpleapi::counter_family_t packets;
    prometheus::simpleapi::counter_metric_t pkt_nop_in, pkt_error_in, pkt_ack_in, pkt_qos_in;
    prometheus::simpleapi::counter_metric_t pkt_hello_in, pkt_ok_in, pkt_whois_in, pkt_rendezvous_in;
    prometheus::simpleapi::counter_metric_t pkt_frame_in, pkt_ext_frame_in, pkt_echo_in;
    prometheus::simpleapi::counter_metric_t pkt_multicast_like_in, pkt_network_credentials_in;
    prometheus::simpleapi::counter_metric_t pkt_network_config_request_in, pkt_network_config_in;
    prometheus::simpleapi::counter_metric_t pkt_multicast_gather_in, pkt_multicast_frame_in;
    prometheus::simpleapi::counter_metric_t pkt_push_direct_paths_in, pkt_user_message_in;
    prometheus::simpleapi::counter_metric_t pkt_remote_trace_in, pkt_path_negotiation_request_in;
    prometheus::simpleapi::counter_metric_t pkt_nop_out, pkt_error_out, pkt_ack_out, pkt_qos_out;
    prometheus::simpleapi::counter_metric_t pkt_hello_out, pkt_ok_out, pkt_whois_out, pkt_rendezvous_out;
    prometheus::simpleapi::counter_metric_t pkt_frame_out, pkt_ext_frame_out, pkt_echo_out;
    prometheus::simpleapi::counter_metric_t pkt_multicast_like_out, pkt_network_credentials_out;
    prometheus::simpleapi::counter_metric_t pkt_network_config_request_out, pkt_network_config_out;
    prometheus::simpleapi::counter_metric_t pkt_multicast_gather_out, pkt_multicast_frame_out;
    prometheus::simpleapi::counter_metric_t pkt_push_direct_paths_out, pkt_user_message_out;
    prometheus::simpleapi::counter_metric_t pkt_remote_trace_out, pkt_path_negotiation_request_out;
    prometheus::simpleapi::counter_family_t packet_errors;
    prometheus::simpleapi::counter_metric_t pkt_error_obj_not_found_in, pkt_error_unsupported_op_in;
    prometheus::simpleapi::counter_metric_t pkt_error_identity_collision_in, pkt_error_need_membership_cert_in;
    prometheus::simpleapi::counter_metric_t pkt_error_network_access_denied_in, pkt_error_unwanted_multicast_in;
    prometheus::simpleapi::counter_metric_t pkt_error_authentication_required_in, pkt_error_internal_server_error_in;
    prometheus::simpleapi::counter_metric_t pkt_error_obj_not_found_out, pkt_error_unsupported_op_out;
    prometheus::simpleapi::counter_metric_t pkt_error_identity_collision_out, pkt_error_need_membership_cert_out;
    prometheus::simpleapi::counter_metric_t pkt_error_network_access_denied_out, pkt_error_unwanted_multicast_out;
    prometheus::simpleapi::counter_metric_t pkt_error_authentication_required_out, pkt_error_internal_server_error_out;
    prometheus::simpleapi::counter_family_t data;
    prometheus::simpleapi::counter_metric_t udp_send, udp_recv, tcp_send, tcp_recv;
    prometheus::simpleapi::gauge_metric_t network_num_joined;
    prometheus::simpleapi::gauge_family_t network_num_multicast_groups;
    prometheus::simpleapi::counter_family_t network_packets;
    prometheus::CustomFamily<prometheus::Histogram<uint64_t>> &peer_latency = _peer_latency_family;
    prometheus::simpleapi::gauge_family_t peer_path_count;
    prometheus::simpleapi::counter_family_t peer_packets;
    prometheus::simpleapi::counter_family_t peer_packet_errors;
    prometheus::simpleapi::gauge_metric_t network_count, member_count;
    prometheus::simpleapi::counter_metric_t network_changes, member_changes, member_auths, member_deauths;
    prometheus::simpleapi::gauge_metric_t network_config_request_queue_size;
    prometheus::simpleapi::counter_metric_t sso_expiration_checks, sso_member_deauth, network_config_request;
    prometheus::simpleapi::gauge_metric_t network_config_request_threads;
    prometheus::simpleapi::counter_metric_t db_get_network, db_get_network_and_member;
    prometheus::simpleapi::counter_metric_t db_get_network_and_member_and_summary;
    prometheus::simpleapi::counter_metric_t db_get_member_list, db_get_network_list;
    prometheus::simpleapi::counter_metric_t db_member_change, db_network_change;
}}
