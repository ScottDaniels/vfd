
GOTCH-YA!
---------

These are things that we ran into which were either missing, not precisely documented in 
the Intel data sheet, or difficult to find. 


Drop Enabled Bit
----------------


Disable Arbitors
----------------
Arbitors must be disabled (the disable bit set) when configuring some of the DCB related
fields.  From the code in the ixgbe driver they need to be disabled for only the  MTQC 
configuration, but there are parts of the data sheet that indicated there are other fields
that require arbitors to be disabled while setting.  

One note, after table 7-25, suggests only MTQC needs to be protected:
  Programming MTQC must be done only during the init phase while software
  must also set RTTDCS.ARBDIS before configuring MTQC and then clear
  RTTDCS.ARBDIS afterwards.

However, in section 4.6.8 (Tx Init) it indicates that the arbitors should be disabled 
while these are configured:
  DTXMXSZRQ, TXPBSIZE, TXPBTHRESH, MTQC, and MNGTXMAP

We took the approach of disabling arbitors during the whole process of configuration
allowing them to be enabled during the final step when the RTTDCS is finally configured.


Disruption
----------
Configuring traffic classes/DCB requires a device reset and thus disrupts traffic. (4.6.11)
Rate parms and bandwidth allocation on the VMs does not distrupt flow.
