library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity store is
  generic (
    DATA_TYPE : integer;
    ADDR_TYPE : integer
  );
  port (
    clk : in  std_logic;
    rst : in std_logic;
    -- data from circuit channel
    dataIn       : in  std_logic_vector(DATA_TYPE - 1 downto 0);
    dataIn_valid : in  std_logic;
    dataIn_ready : out std_logic;
    -- address from circuit channel
    addrIn       : in  std_logic_vector(ADDR_TYPE - 1 downto 0);
    addrIn_valid : in  std_logic;
    addrIn_ready : out std_logic;
    -- data to interface channel
    dataToMem       : out std_logic_vector(DATA_TYPE - 1 downto 0);
    dataToMem_valid : out std_logic;
    dataToMem_ready : in  std_logic;
    -- address to interface channel
    addrOut       : out std_logic_vector(ADDR_TYPE - 1 downto 0);
    addrOut_valid : out std_logic;
    addrOut_ready : in  std_logic
  );
end entity;

architecture arch of store is
begin
  -- data
  dataToMem       <= dataIn;
  dataToMem_valid <= dataIn_valid;
  dataIn_ready    <= dataToMem_ready;
  -- addr
  addrOut         <= addrIn;
  addrOut_valid   <= addrIn_valid;
  addrIn_ready    <= addrOut_ready;
end architecture;
