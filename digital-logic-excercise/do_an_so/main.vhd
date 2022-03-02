
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity counter_person is
	Port ( 
		clk : in  STD_LOGIC;
		sw_enable : in  STD_LOGIC;
		sensor_1 : in STD_LOGIC;				-- hong ngoai 1 as button1
		sensor_2: in STD_LOGIC;				--hong ngoai 2 as button2
		lcd_rw	: out std_logic;				-- read & write control
		lcd_e 	: out std_logic;				-- enable control
		lcd_rs	: out std_logic;				-- data or command control
		data  	: out std_logic_vector(7 downto 0)); -- data field for transfer from fpga to lcd
end counter_person;

architecture Behavioral of counter_person is
	signal persion_number_go_out: integer := 0;
	signal persion_number_come_in: integer := 0;
	type arr_number_splited is array (1 downto 0) of integer;
	signal nguoi_vao :arr_number_splited := (0,0);
	signal nguoi_ra :arr_number_splited := (0,0);

	signal count_clk: integer := 0;
	signal clk_1hz: std_logic := '0'; 
	--------------------------------------------------
	constant N: integer :=19; 
	type arr is array (1 to N) of std_logic_vector(7 downto 0);
	-- update string for team
	signal datas : arr :=    (X"38",X"0c",X"06",X"01",X"80",
	x"10",x"20",x"20",	-- > number_persons_in 78
	x"20",x"11",x"20",x"20",	-- < number_persion_out  11 12
	x"20",x"50",x"45",x"52",x"53",x"4F",x"4E");
begin

----------------------------------------------
Div : process(clk)
	begin
		if(falling_edge(clk)) then 
		 	-- cu (2*2M) /50M xung thi check sensor 1 lan 
			
			if(count_clk < 2000000) then 
				count_clk <= count_clk + 1; 
			else
				count_clk <= 0; 
				clk_1hz <= not clk_1hz; 
			end if; 
		end if; 
	end process; 
-----------------------------------------------
countp: process
variable check : integer := 0;
variable start_wait1 : integer := 0;
variable start_wait2 : integer := 0;
begin
	if(falling_edge(clk_1hz)) then 
		-- doi cho den khi nguoi di qua cam bien 1
		if (sensor_1 = '0' and start_wait1 = 1) then
			start_wait1 = 0;
		end if;
		
		-- doi cho den khi nguoi di qua cam bien 2
		if (sensor_2 = '0' and start_wait2 = 1) then
			start_wait2 = 0;
		end if;

		-- khi nguoi da di qua cam bien va sensor = 1
		if(sensor_1 = '1' and start_wait1 = 0 ) then 
			start_wait1 = 1 ;
			-- khi da di qua cam bien sensor_2 thi check = 3
			-- kiem tra nguoi da di qua sensor_2 truoc do hay ko 
			if ( check = 3 ) then 
				check := 0;
				-- tang so nguoi ra ngoai 
				if (nguoi_ra(0) = 9) then 
					nguoi_ra(1) <= nguoi_ra(1) + 1;
					nguoi_ra(0) <= 0;
				else 
					nguoi_ra(0) <= nguoi_ra(0) + 1;
				end if;
			else 
				-- neu day la lan qua thu 2 cung 1 cam bien >> reset
				if ( check = 1) then 
					check := 0; -- reset state 
				-- neu day la lan qua dau tien >> gan check = 1
				else 
					check := 1;
				end if;
			end if;
		
		elsif(sensor_2 = '1' and start_wait2 ='0' ) then
			start_wait2 = 1 ; --wait for sensor_2 = 0;
			-- khi da di qua cam bien sensor_1 thi check = 3
			-- kiem tra nguoi da di qua sensor_1 truoc do hay ko 
			 if (check = 1) then
					check := 0; -- reset state 
					--tang so nguoi vao trong 
					if (nguoi_vao(0) = 9) then 
						nguoi_vao(1) <= nguoi_vao(1) + 1;
						nguoi_vao(0) <= 0;
					else 
						nguoi_vao(0) <= nguoi_vao(0) + 1;
					end if;
			else
				-- neu day la lan qua thu 2 cung 1 cam bien >> reset
				if ( check = 3 ) then 
					check := 0;
				else 
				--neu day la lan qua lan dau tien thi check = 3
					check := 3;
				end if;
				
			 end if;
	end if; 
end process;
-----------------------------------------------
lcd_rw <= '0';
-----------------------------------------------
lcd : process(clk)
	variable i : integer := 0;
	variable j : integer := 1;
	begin
	if clk'event and clk = '1' then
		if i <= 1000000 then
			i := i + 1;
			lcd_e <= '1';
			-- bieu dien hang chuc 
			if(j = 7) then
				-- so 1 tuong ung voi X"31" tuong tu voi cac so khac 
				if( nguoi_vao(1) = 1) then data <= X"31"; 
				elsif( nguoi_vao(1) = 2) then data <= X"32"; 
				elsif( nguoi_vao(1) = 3) then data <= X"33"; 
				elsif( nguoi_vao(1) = 4) then data <= X"34"; 
				elsif( nguoi_vao(1) = 5) then data <= X"35"; 
				elsif( nguoi_vao(1) = 6) then data <= X"36"; 
				elsif( nguoi_vao(1) = 7) then data <= X"37"; 
				elsif( nguoi_vao(1) = 8) then data <= X"38"; 
				elsif( nguoi_vao(1) = 9) then data <= X"39"; 
				else data <= X"0";
				end if; 
			-- bieuu dien han don vi 
			elsif(j = 8) then
				if( nguoi_vao(0) = 0) then data <= X"31"; 
					elsif( nguoi_vao(0) = 2) then data <= X"32"; 
					elsif( nguoi_vao(0) = 3) then data <= X"33"; 
					elsif( nguoi_vao(0) = 4) then data <= X"34"; 
					elsif( nguoi_vao(0) = 5) then data <= X"35"; 
					elsif( nguoi_vao(0) = 6) then data <= X"36"; 
					elsif( nguoi_vao(0) = 7) then data <= X"37"; 
					elsif( nguoi_vao(0) = 8) then data <= X"38"; 
					elsif( nguoi_vao(0) = 9) then data <= X"39"; 
					else data <= X"0";
				end if; 
				
			-- bieu dien hang chuc 
			elsif(j = 11) then
				if( nguoi_ra(1) = 1) then data <= X"31"; 
				elsif( nguoi_ra(1) = 2) then data <= X"32"; 
				elsif( nguoi_ra(1) = 3) then data <= X"33"; 
				elsif( nguoi_ra(1) = 4) then data <= X"34"; 
				elsif( nguoi_ra(1) = 5) then data <= X"35"; 
				elsif( nguoi_ra(1) = 6) then data <= X"36"; 
				elsif( nguoi_ra(1) = 7) then data <= X"37"; 
				elsif( nguoi_ra(1) = 8) then data <= X"38"; 
				elsif( nguoi_ra(1) = 9) then data <= X"39"; 
				else data <= X"0";				
				end if; 
			-- bieu dien hang don vi 
			elsif(j = 12) then
					if( nguoi_ra(0) = 1) then data <= X"31"; 
					elsif( nguoi_ra(0) = 2) then data <= X"32"; 
					elsif( nguoi_ra(0) = 3) then data <= X"33"; 
					elsif( nguoi_ra(0) = 4) then data <= X"34"; 
					elsif( nguoi_ra(0) = 5) then data <= X"35"; 
					elsif( nguoi_ra(0) = 6) then data <= X"36"; 
					elsif( nguoi_ra(0) = 7) then data <= X"37"; 
					elsif( nguoi_ra(0) = 8) then data <= X"38"; 
					elsif( nguoi_ra(0) = 9) then data <= X"39"; 
					else data <= X"0";
					end if; 		
			-- cac vi tri datas(j) se la khoi tao lcd va hien thi chu "PERSON" 
			else data <= datas(j)(7 downto 0); 
			end if;
		-- delay de gui du lieu , lenh vao lcd 
		elsif i > 1000000 and i < 2000000 then
			i := i + 1;
			lcd_e <= '0';
		elsif i = 2000000 then
			j := j + 1;
			i := 0;
		end if;
		-- che do gui lenh
		if j <= 5  then
			lcd_rs <= '0';    --command signal
		-- che do gui du lieu 
		elsif j > 5   then
			lcd_rs <= '1';   --data signal
		end if;
		-- reset ve che do gui lenh 
		if j = N+1 then  --repeated display of data
			j := 5;
		end if;
	end if;
end process;

end Behavioral;

