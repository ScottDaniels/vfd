
#ifndef _VFD_MLX5_H
#define _VFD_MLX5_H

#include "vfdlib.h" 
#include "sriov.h" 

struct mlx5_tc_cfg {
	char policy[8];
	int32_t min_bw;
	int32_t max_bw;
};

// ------------- prototypes ----------------------------------------------
int vfd_mlx5_get_ifname(portid_t port_id, char *ifname);

int vfd_mlx5_set_vf_mac_addr(portid_t port_id, uint16_t vf_id, const char* mac, uint8_t on);
int vfd_mlx5_set_vf_def_mac_addr(portid_t port, uint16_t vf_id, const char *mac_addr);
int vfd_mlx5_vf_mac_remove(portid_t port_id, uint16_t vf_id);
int vfd_mlx5_set_vf_vlan_stripq(portid_t port, uint16_t vf, uint8_t on);
int vfd_mlx5_set_vf_vlan_insert(portid_t port, uint16_t vf_id, uint16_t vlan_id);
int vfd_mlx5_set_vf_cvlan_insert(portid_t port_id, uint16_t vf_id, uint16_t vlan_id);
int vfd_mlx5_set_vf_mac_anti_spoof(portid_t port_id, uint16_t vf_id, uint8_t on);
int vfd_mlx5_set_vf_min_rate(portid_t port_id, uint16_t vf_id, uint16_t rate);
int vfd_mlx5_set_vf_rate_limit(portid_t port_id, uint16_t vf_id, uint16_t rate);
int vfd_mlx5_set_vf_link_status(portid_t port_id, uint16_t vf_id, int status);
uint32_t vfd_mlx5_get_pf_spoof_stats(portid_t port_id);
int vfd_mlx5_get_num_vfs(portid_t port_id);
int vfd_mlx5_get_vf_stats(portid_t port_id, uint16_t vf_id, struct rte_eth_stats *stats);
uint64_t vfd_mlx5_get_vf_sysfs_counter(char *ifname, const char *counter,  uint16_t vf_id);
uint64_t vfd_mlx5_get_vf_ethtool_counter(char *ifname, const char *counter);
uint64_t vfd_mlx5_get_vf_spoof_stats(portid_t port_id, uint16_t vf_id);
int vfd_mlx5_pf_vf_offset(char *pciid);
int vfd_mlx5_set_vf_vlan_filter(portid_t port_id, uint16_t vlan_id, uint64_t vf_mask, uint8_t on);
int vfd_mlx5_set_vf_promisc(portid_t port_id, uint16_t vf_id, uint8_t on);
int vfd_mlx5_set_qos_pf(portid_t port_id, tc_class_t **tc_config, uint8_t ntcs);
int vfd_mlx5_set_prio_trust(portid_t port_id);
int vfd_mlx5_set_mirror( portid_t port_id, uint32_t vf, uint8_t target, uint8_t direction);
int vfd_mlx5_set_vf_tcqos( portid_t port_id, uint32_t vf, uint8_t tc, uint32_t rate );

#endif
