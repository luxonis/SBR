# sbr-util
Utility to view and manipulate SBR binary images

## Usage

```
./sbr-util path/to/sbr/image
```

### Example Output

```
./sbr-util my_app.dap
ID        BR
VALID     Name                     Size(B)     Offset      Checksum      Type    Flags
true      __firmware               14980448    512         0x1C735FE6    0       1
true      pipeline                 868         15728640    0xA74C03E0    0       0
true      assets                   43          16777216    0x361B3B02    0       0
true      asset_storage            14488768    17825792    0x5B3280FC    0       0
false                              0           0           0x00000000    0       0
false                              0           0           0x00000000    0       0
false                              0           0           0x00000000    0       0
false                              0           0           0x00000000    0       0
false                              0           0           0x00000000    0       0
false                              0           0           0x00000000    0       0
false                              0           0           0x00000000    0       0
false                              0           0           0x00000000    0       0
false                              0           0           0x00000000    0       0
false                              0           0           0x00000000    0       0
false                              0           0           0x00000000    0       0
false                              0           0           0x00000000    0       0
false                              0           0           0x00000000    0       0
```
