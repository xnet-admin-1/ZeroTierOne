#ifndef METRICS_H_
#define METRICS_H_

#include <string>
#include <memory>

// Stubbed out for Android - no prometheus dependency
namespace prometheus {
    struct Registry {};
    template<typename T> struct Histogram {
        void Observe(T) {}
        Histogram& operator=(const Histogram&) { return *this; }
    };
    template<typename T> struct CustomFamily {
        Histogram<uint64_t> Add(std::initializer_list<std::pair<std::string,std::string>>, const std::initializer_list<uint64_t>&) {
            static Histogram<uint64_t> h; return h;
        }
    };
    namespace simpleapi {
        extern std::shared_ptr<Registry> registry_ptr;
        struct counter_metric_t {
            counter_metric_t& operator++() { return *this; }
            counter_metric_t operator++(int) { return *this; }
            counter_metric_t& operator+=(int) { return *this; }
            void Increment(double v=1) {}
        };
        struct gauge_metric_t {
            gauge_metric_t& operator++() { return *this; }
            gauge_metric_t operator++(int) { return *this; }
            gauge_metric_t& operator--() { return *this; }
            gauge_metric_t operator--(int) { return *this; }
            gauge_metric_t& operator+=(int) { return *this; }
            gauge_metric_t& operator-=(int) { return *this; }
            void Set(double) {}
            void Increment(double v=1) {}
            void Decrement(double v=1) {}
        };
        struct counter_family_t {
            counter_metric_t Add(std::initializer_list<std::pair<std::string,std::string>>) {
                static counter_metric_t m; return m;
            }
        };
        struct gauge_family_t {
            gauge_metric_t Add(std::initializer_list<std::pair<std::string,std::string>>) {
                static gauge_metric_t m; return m;
            }
        };
    }
}

namespace ZeroTier {
namespace Metrics {
    // Packet counters
    extern prometheus::simpleapi::counter_family_t packets;
    extern prometheus::simpleapi::counter_metric_t pkt_nop_in, pkt_error_in, pkt_ack_in, pkt_qos_in;
    extern prometheus::simpleapi::counter_metric_t pkt_hello_in, pkt_ok_in, pkt_whois_in, pkt_rendezvous_in;
    extern prometheus::simpleapi::counter_metric_t pkt_frame_in, pkt_ext_frame_in, pkt_echo_in;
    extern prometheus::simpleapi::counter_metric_t pkt_multicast_like_in, pkt_network_credentials_in;
    extern prometheus::simpleapi::counter_metric_t pkt_network_config_request_in, pkt_network_config_in;
    extern prometheus::simpleapi::counter_metric_t pkt_multicast_gather_in, pkt_multicast_frame_in;
    extern prometheus::simpleapi::counter_metric_t pkt_push_direct_paths_in, pkt_user_message_in;
    extern prometheus::simpleapi::counter_metric_t pkt_remote_trace_in, pkt_path_negotiation_request_in;
    extern prometheus::simpleapi::counter_metric_t pkt_nop_out, pkt_error_out, pkt_ack_out, pkt_qos_out;
    extern prometheus::simpleapi::counter_metric_t pkt_hello_out, pkt_ok_out, pkt_whois_out, pkt_rendezvous_out;
    extern prometheus::simpleapi::counter_metric_t pkt_frame_out, pkt_ext_frame_out, pkt_echo_out;
    extern prometheus::simpleapi::counter_metric_t pkt_multicast_like_out, pkt_network_credentials_out;
    extern prometheus::simpleapi::counter_metric_t pkt_network_config_request_out, pkt_network_config_out;
    extern prometheus::simpleapi::counter_metric_t pkt_multicast_gather_out, pkt_multicast_frame_out;
    extern prometheus::simpleapi::counter_metric_t pkt_push_direct_paths_out, pkt_user_message_out;
    extern prometheus::simpleapi::counter_metric_t pkt_remote_trace_out, pkt_path_negotiation_request_out;
    // Packet errors
    extern prometheus::simpleapi::counter_family_t packet_errors;
    extern prometheus::simpleapi::counter_metric_t pkt_error_obj_not_found_in, pkt_error_unsupported_op_in;
    extern prometheus::simpleapi::counter_metric_t pkt_error_identity_collision_in, pkt_error_need_membership_cert_in;
    extern prometheus::simpleapi::counter_metric_t pkt_error_network_access_denied_in, pkt_error_unwanted_multicast_in;
    extern prometheus::simpleapi::counter_metric_t pkt_error_authentication_required_in, pkt_error_internal_server_error_in;
    extern prometheus::simpleapi::counter_metric_t pkt_error_obj_not_found_out, pkt_error_unsupported_op_out;
    extern prometheus::simpleapi::counter_metric_t pkt_error_identity_collision_out, pkt_error_need_membership_cert_out;
    extern prometheus::simpleapi::counter_metric_t pkt_error_network_access_denied_out, pkt_error_unwanted_multicast_out;
    extern prometheus::simpleapi::counter_metric_t pkt_error_authentication_required_out, pkt_error_internal_server_error_out;
    // Data
    extern prometheus::simpleapi::counter_family_t data;
    extern prometheus::simpleapi::counter_metric_t udp_send, udp_recv, tcp_send, tcp_recv;
    // Network
    extern prometheus::simpleapi::gauge_metric_t network_num_joined;
    extern prometheus::simpleapi::gauge_family_t network_num_multicast_groups;
    extern prometheus::simpleapi::counter_family_t network_packets;
    // Peer
    extern prometheus::CustomFamily<prometheus::Histogram<uint64_t>> &peer_latency;
    extern prometheus::simpleapi::gauge_family_t peer_path_count;
    extern prometheus::simpleapi::counter_family_t peer_packets;
    extern prometheus::simpleapi::counter_family_t peer_packet_errors;
    // Controller
    extern prometheus::simpleapi::gauge_metric_t network_count, member_count;
    extern prometheus::simpleapi::counter_metric_t network_changes, member_changes, member_auths, member_deauths;
    extern prometheus::simpleapi::gauge_metric_t network_config_request_queue_size;
    extern prometheus::simpleapi::counter_metric_t sso_expiration_checks, sso_member_deauth, network_config_request;
    extern prometheus::simpleapi::gauge_metric_t network_config_request_threads;
    extern prometheus::simpleapi::counter_metric_t db_get_network, db_get_network_and_member;
    extern prometheus::simpleapi::counter_metric_t db_get_network_and_member_and_summary;
    extern prometheus::simpleapi::counter_metric_t db_get_member_list, db_get_network_list;
    extern prometheus::simpleapi::counter_metric_t db_member_change, db_network_change;
}
}

#endif
