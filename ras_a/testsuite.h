/** @file
 *    @brief MAVLink comm protocol testsuite generated from ras_a.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef RAS_A_TESTSUITE_H
#define RAS_A_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_development(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_ras_a(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_development(system_id, component_id, last_msg);
    mavlink_test_ras_a(system_id, component_id, last_msg);
}
#endif

#include "../development/testsuite.h"


static void mavlink_test_poi_report(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_POI_REPORT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_poi_report_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,963498296,963498504,963498712,963498920,241.0,269.0,297.0,963499752,353.0,381.0,409.0,{ 437.0, 438.0, 439.0, 440.0 },549.0,577.0,605.0,633.0,661.0,22227,171,238,49,116,183
    };
    mavlink_poi_report_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_utc_detected = packet_in.time_utc_detected;
        packet1.time_utc_updated = packet_in.time_utc_updated;
        packet1.uid = packet_in.uid;
        packet1.time_boot_ms = packet_in.time_boot_ms;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.alt_msl = packet_in.alt_msl;
        packet1.alt_ellip = packet_in.alt_ellip;
        packet1.alt_ground = packet_in.alt_ground;
        packet1.classification = packet_in.classification;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        packet1.dist = packet_in.dist;
        packet1.vel_n = packet_in.vel_n;
        packet1.vel_e = packet_in.vel_e;
        packet1.vel_d = packet_in.vel_d;
        packet1.hdg = packet_in.hdg;
        packet1.ttl = packet_in.ttl;
        packet1.confidence_overall = packet_in.confidence_overall;
        packet1.confidence_detection = packet_in.confidence_detection;
        packet1.confidence_classification = packet_in.confidence_classification;
        packet1.confidence_localization = packet_in.confidence_localization;
        packet1.status_flags = packet_in.status_flags;
        
        mav_array_memcpy(packet1.q, packet_in.q, sizeof(float)*4);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_POI_REPORT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_POI_REPORT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_poi_report_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_poi_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_poi_report_pack(system_id, component_id, &msg , packet1.uid , packet1.time_boot_ms , packet1.time_utc_detected , packet1.time_utc_updated , packet1.confidence_overall , packet1.confidence_detection , packet1.confidence_classification , packet1.confidence_localization , packet1.ttl , packet1.status_flags , packet1.latitude , packet1.longitude , packet1.alt_msl , packet1.alt_ellip , packet1.alt_ground , packet1.classification , packet1.x , packet1.y , packet1.z , packet1.q , packet1.dist , packet1.vel_n , packet1.vel_e , packet1.vel_d , packet1.hdg );
    mavlink_msg_poi_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_poi_report_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.uid , packet1.time_boot_ms , packet1.time_utc_detected , packet1.time_utc_updated , packet1.confidence_overall , packet1.confidence_detection , packet1.confidence_classification , packet1.confidence_localization , packet1.ttl , packet1.status_flags , packet1.latitude , packet1.longitude , packet1.alt_msl , packet1.alt_ellip , packet1.alt_ground , packet1.classification , packet1.x , packet1.y , packet1.z , packet1.q , packet1.dist , packet1.vel_n , packet1.vel_e , packet1.vel_d , packet1.hdg );
    mavlink_msg_poi_report_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_poi_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_poi_report_send(MAVLINK_COMM_1 , packet1.uid , packet1.time_boot_ms , packet1.time_utc_detected , packet1.time_utc_updated , packet1.confidence_overall , packet1.confidence_detection , packet1.confidence_classification , packet1.confidence_localization , packet1.ttl , packet1.status_flags , packet1.latitude , packet1.longitude , packet1.alt_msl , packet1.alt_ellip , packet1.alt_ground , packet1.classification , packet1.x , packet1.y , packet1.z , packet1.q , packet1.dist , packet1.vel_n , packet1.vel_e , packet1.vel_d , packet1.hdg );
    mavlink_msg_poi_report_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("POI_REPORT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_POI_REPORT) != NULL);
#endif
}

static void mavlink_test_exploration_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EXPLORATION_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_exploration_status_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,18067,18171,18275,199,10
    };
    mavlink_exploration_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.time_to_timeout = packet_in.time_to_timeout;
        packet1.progress = packet_in.progress;
        packet1.denominator = packet_in.denominator;
        packet1.flags = packet_in.flags;
        packet1.exploration_id = packet_in.exploration_id;
        packet1.level = packet_in.level;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EXPLORATION_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EXPLORATION_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exploration_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_exploration_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exploration_status_pack(system_id, component_id, &msg , packet1.time_usec , packet1.time_to_timeout , packet1.exploration_id , packet1.progress , packet1.denominator , packet1.flags , packet1.level );
    mavlink_msg_exploration_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exploration_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.time_to_timeout , packet1.exploration_id , packet1.progress , packet1.denominator , packet1.flags , packet1.level );
    mavlink_msg_exploration_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_exploration_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exploration_status_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.time_to_timeout , packet1.exploration_id , packet1.progress , packet1.denominator , packet1.flags , packet1.level );
    mavlink_msg_exploration_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("EXPLORATION_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_EXPLORATION_STATUS) != NULL);
#endif
}

static void mavlink_test_exploration_info(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EXPLORATION_INFO >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_exploration_info_t packet_in = {
        963497464,963497672,963497880,101.0,129.0,157.0,185.0,963498920,963499128,269.0,297.0,325.0,353.0,963500168,963500376,963500584,465.0,963501000,963501208,963501416,577.0,1,68
    };
    mavlink_exploration_info_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_limit = packet_in.time_limit;
        packet1.boundaries_p1_lat = packet_in.boundaries_p1_lat;
        packet1.boundaries_p1_lon = packet_in.boundaries_p1_lon;
        packet1.boundaries_p1_alt = packet_in.boundaries_p1_alt;
        packet1.boundaries_p1_x = packet_in.boundaries_p1_x;
        packet1.boundaries_p1_y = packet_in.boundaries_p1_y;
        packet1.boundaries_p1_z = packet_in.boundaries_p1_z;
        packet1.boundaries_p2_lat = packet_in.boundaries_p2_lat;
        packet1.boundaries_p2_lon = packet_in.boundaries_p2_lon;
        packet1.boundaries_p2_x = packet_in.boundaries_p2_x;
        packet1.boundaries_p2_y = packet_in.boundaries_p2_y;
        packet1.boundaries_p3_alt = packet_in.boundaries_p3_alt;
        packet1.boundaries_p3_z = packet_in.boundaries_p3_z;
        packet1.ingress_portal_id = packet_in.ingress_portal_id;
        packet1.ingress_portal_lat = packet_in.ingress_portal_lat;
        packet1.ingress_portal_lon = packet_in.ingress_portal_lon;
        packet1.ingress_portal_alt = packet_in.ingress_portal_alt;
        packet1.egress_portal_id = packet_in.egress_portal_id;
        packet1.egress_portal_lat = packet_in.egress_portal_lat;
        packet1.egress_portal_lon = packet_in.egress_portal_lon;
        packet1.egress_portal_alt = packet_in.egress_portal_alt;
        packet1.exploration_id = packet_in.exploration_id;
        packet1.behaviour_after_stopping = packet_in.behaviour_after_stopping;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EXPLORATION_INFO_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EXPLORATION_INFO_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exploration_info_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_exploration_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exploration_info_pack(system_id, component_id, &msg , packet1.exploration_id , packet1.time_limit , packet1.behaviour_after_stopping , packet1.boundaries_p1_lat , packet1.boundaries_p1_lon , packet1.boundaries_p1_alt , packet1.boundaries_p1_x , packet1.boundaries_p1_y , packet1.boundaries_p1_z , packet1.boundaries_p2_lat , packet1.boundaries_p2_lon , packet1.boundaries_p2_x , packet1.boundaries_p2_y , packet1.boundaries_p3_alt , packet1.boundaries_p3_z , packet1.ingress_portal_id , packet1.ingress_portal_lat , packet1.ingress_portal_lon , packet1.ingress_portal_alt , packet1.egress_portal_id , packet1.egress_portal_lat , packet1.egress_portal_lon , packet1.egress_portal_alt );
    mavlink_msg_exploration_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exploration_info_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.exploration_id , packet1.time_limit , packet1.behaviour_after_stopping , packet1.boundaries_p1_lat , packet1.boundaries_p1_lon , packet1.boundaries_p1_alt , packet1.boundaries_p1_x , packet1.boundaries_p1_y , packet1.boundaries_p1_z , packet1.boundaries_p2_lat , packet1.boundaries_p2_lon , packet1.boundaries_p2_x , packet1.boundaries_p2_y , packet1.boundaries_p3_alt , packet1.boundaries_p3_z , packet1.ingress_portal_id , packet1.ingress_portal_lat , packet1.ingress_portal_lon , packet1.ingress_portal_alt , packet1.egress_portal_id , packet1.egress_portal_lat , packet1.egress_portal_lon , packet1.egress_portal_alt );
    mavlink_msg_exploration_info_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_exploration_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exploration_info_send(MAVLINK_COMM_1 , packet1.exploration_id , packet1.time_limit , packet1.behaviour_after_stopping , packet1.boundaries_p1_lat , packet1.boundaries_p1_lon , packet1.boundaries_p1_alt , packet1.boundaries_p1_x , packet1.boundaries_p1_y , packet1.boundaries_p1_z , packet1.boundaries_p2_lat , packet1.boundaries_p2_lon , packet1.boundaries_p2_x , packet1.boundaries_p2_y , packet1.boundaries_p3_alt , packet1.boundaries_p3_z , packet1.ingress_portal_id , packet1.ingress_portal_lat , packet1.ingress_portal_lon , packet1.ingress_portal_alt , packet1.egress_portal_id , packet1.egress_portal_lat , packet1.egress_portal_lon , packet1.egress_portal_alt );
    mavlink_msg_exploration_info_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("EXPLORATION_INFO") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_EXPLORATION_INFO) != NULL);
#endif
}

static void mavlink_test_exploration_return_position(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_exploration_return_position_t packet_in = {
        93372036854775807ULL,963497880,963498088,963498296,963498504,963498712,213.0,241.0,269.0,297.0
    };
    mavlink_exploration_return_position_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_usec = packet_in.time_usec;
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.altitude = packet_in.altitude;
        packet1.relative_alt = packet_in.relative_alt;
        packet1.geoid_alt = packet_in.geoid_alt;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        packet1.yaw = packet_in.yaw;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exploration_return_position_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_exploration_return_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exploration_return_position_pack(system_id, component_id, &msg , packet1.time_usec , packet1.latitude , packet1.longitude , packet1.altitude , packet1.relative_alt , packet1.geoid_alt , packet1.x , packet1.y , packet1.z , packet1.yaw );
    mavlink_msg_exploration_return_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exploration_return_position_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_usec , packet1.latitude , packet1.longitude , packet1.altitude , packet1.relative_alt , packet1.geoid_alt , packet1.x , packet1.y , packet1.z , packet1.yaw );
    mavlink_msg_exploration_return_position_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_exploration_return_position_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_exploration_return_position_send(MAVLINK_COMM_1 , packet1.time_usec , packet1.latitude , packet1.longitude , packet1.altitude , packet1.relative_alt , packet1.geoid_alt , packet1.x , packet1.y , packet1.z , packet1.yaw );
    mavlink_msg_exploration_return_position_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("EXPLORATION_RETURN_POSITION") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_EXPLORATION_RETURN_POSITION) != NULL);
#endif
}

static void mavlink_test_ras_a(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_poi_report(system_id, component_id, last_msg);
    mavlink_test_exploration_status(system_id, component_id, last_msg);
    mavlink_test_exploration_info(system_id, component_id, last_msg);
    mavlink_test_exploration_return_position(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // RAS_A_TESTSUITE_H
