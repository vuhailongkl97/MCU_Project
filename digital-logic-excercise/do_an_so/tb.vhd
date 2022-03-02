--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:24:12 04/19/2019
-- Design Name:   
-- Module Name:   E:/Users/VuHaiLong/Desktop/PTIT4/do_an_so/do_an_so/tb.vhd
-- Project Name:  do_an_so
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: stepper_test
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb IS
END tb;
 
ARCHITECTURE behavior OF tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT stepper_test
    PORT(
         clk : IN  std_logic;
         sw_dir : IN  std_logic;
         sw_enable : IN  std_logic;
         sw_speed_up : IN  std_logic;
         sw_speed_down : IN  std_logic;
         lcd_rw : OUT  std_logic;
         lcd_e : OUT  std_logic;
         lcd_rs : OUT  std_logic;
         data : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal sw_dir : std_logic := '0';
   signal sw_enable : std_logic := '0';
   signal sw_speed_up : std_logic := '0';
   signal sw_speed_down : std_logic := '0';

 	--Outputs
   signal lcd_rw : std_logic :='0';
   signal lcd_e : std_logic :='0';
   signal lcd_rs : std_logic:='0';
   signal data : std_logic_vector(7 downto 0):="00010101";

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN 
 
	-- Instantiate the Unit Under Test (UUT)
   uut: stepper_test PORT MAP (
          clk => clk,
          sw_dir => sw_dir,
          sw_enable => sw_enable,
          sw_speed_up => sw_speed_up,
          sw_speed_down => sw_speed_down,
          lcd_rw => lcd_rw,
          lcd_e => lcd_e,
          lcd_rs => lcd_rs,
          data => data
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;

END;
