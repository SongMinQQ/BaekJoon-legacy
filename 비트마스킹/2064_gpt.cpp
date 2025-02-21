#include <bits/stdc++.h>
using namespace std;

// 최대 N개 IP, 각 IP는 [i][0..3] 형태 (바이트 단위)
int addressArr[1002][4];
int n;

// 공통으로 i번째 바이트가 모두 같은지 여부 확인
bool allSameByte(int i) {
    // addressArr[0][i] 기준으로 비교
    int refVal = addressArr[0][i];
    for(int r = 1; r < n; r++){
        if(addressArr[r][i] != refVal)
            return false;
    }
    return true;
}

// i번째 바이트에서, "왼쪽으로부터 몇 비트가 모든 IP에 대해 같은가"를 찾아냄
//   - 예) 모든 IP의 i바이트 중 최솟값, 최댓값 구해서 xor -> 최상위 1비트 위치
//   - 반환값: 0~8 (0이면 바이트가 전혀 안 맞고, 8이면 전부 동일)
int commonBitsInByte(int i) {
    // i바이트에 대해 min/max를 구한다
    int mn = 255, mx = 0;
    for(int r = 0; r < n; r++){
        int val = addressArr[r][i];
        mn = min(mn, val);
        mx = max(mx, val);
    }
    int diff = mn ^ mx; // 달라지는 비트가 어디까지인지 확인

    if(diff == 0) {
        // 전부 같은 바이트 -> 8비트 다 동일
        return 8;
    }

    // diff != 0 이면, 왼쪽(상위)부터 연속으로 같은 비트 수를 찾아야 한다.
    // 예: diff = 0b00111000 이면, 최상위 1비트가 5번째 (b5)라면, 
    //     => 공통 비트 = 3 (8 - 5 = 3) 이런 식...
    // 좀 더 간단한 방법: 
    //  1) 비트를 왼쪽으로 한 칸씩 shift하며 최대 8번 검사 
    //  2) 왼쪽에서부터 처음 1이 나타나는 순간 count
    // 여러 방식이 가능하나, 여기서는 "가장 왼쪽 1비트를 찾는" 과정을 구현

    // 방법1) 8비트를 전부 왼쪽 shift 하며 체크
    int commonCount = 0; 
    // 8번 반복
    for(int shiftCount = 0; shiftCount < 8; shiftCount++){
        // 최상위 비트가 1인지 확인하기 위해 diff & 0x80 (10000000) 
        // 를 검사한 뒤 shift
        if((diff & 0x80) != 0) {
            // 왼쪽 가장 큰 자리에서 차이가 났다 = (0+commonCount) 만큼만 같음
            break;
        } else {
            // 아직 0이면 => 그 비트는 동일
            commonCount++;
            diff <<= 1; 
        }
    }
    return commonCount; // 0~7 사이
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        string ip; 
        cin >> ip;
        // ip "x.x.x.x" 파싱
        {
            istringstream iss(ip);
            for(int j = 0; j < 4; j++){
                string part;
                getline(iss, part, '.');
                addressArr[i][j] = stoi(part);
            }
        }
    }

    // n=1일 때는 그냥 자기 자신만 /32
    if(n == 1){
        cout << addressArr[0][0] << "." << addressArr[0][1] << "." 
             << addressArr[0][2] << "." << addressArr[0][3] << "\n";
        cout << "255.255.255.255\n";
        return 0;
    }

    // 최종 마스크, 네트워크 주소(각 4바이트)
    int mask[4] = {0,0,0,0};
    int netAddr[4] = {0,0,0,0};

    // 먼저, 0~3 바이트 순으로 확인하며 
    // "모두 같은 바이트"면 mask=255, 
    // "달라지면 그 바이트에서 partial bit 계산 -> 나머지=0, break"
    int differIndex = -1; // -1이면 아직 차이 발견 X
    for(int i=0; i<4; i++){
        if(allSameByte(i)) {
            // i번째 바이트 모두 동일 -> mask=255
            mask[i] = 255;
            // 네트워크 주소도 addresses[0]의 i바이트 그대로
            netAddr[i] = addressArr[0][i];
        } else {
            // 차이가 발생한 첫 바이트
            differIndex = i;

            // i바이트에서 왼쪽으로 몇 비트가 같은지 계산
            int cBits = commonBitsInByte(i);
            // cBits만큼만 1로 만들어야 한다(나머지 bit=0)
            // 예: cBits=4 -> 11110000(b) = 240(dec)
            //     cBits=7 -> 11111110(b)=254, cBits=0 -> 00000000(b)=0
            //     cBits=8 -> 11111111(b)=255(사실 이 경우 allSameByte였을 것)

            int bitmask = 0; 
            for(int b=0; b<cBits; b++){
                // 왼쪽부터 cBits개 -> ex) cBits=4 => b=0..3
                bitmask |= (1 << (7 - b)); 
            }
            // i바이트 마스크 설정
            mask[i] = bitmask & 0xFF; 
            
            // 네트워크 주소 = (첫 IP의 i바이트) & bitmask
            netAddr[i] = addressArr[0][i] & mask[i];
            
            // 나머지 바이트(i+1 .. 3)는 마스크=0, netAddr=0
            for(int k = i+1; k < 4; k++){
                mask[k] = 0;
                netAddr[k] = 0;
            }
            break;
        }
    }

    // 만약 differIndex가 -1이면(즉 끝까지 차이 못 찾음) => 전부 동일 => /32
    // 이미 위에서 allSameByte(i)=true일 때 mask[i]=255, netAddr[i]=addresses[0][i]를 했으니
    // 실제로 255.255.255.255 / (주소 동일)이 되어 있음
    // 별도 처리 필요 없지만, 혹시 명시해두면:
    if(differIndex == -1) {
        // 이미 mask=255.255.255.255 , netAddr=그 IP
    }

    // 출력
    cout << netAddr[0] << "." << netAddr[1] << "." << netAddr[2] << "." << netAddr[3] << "\n";
    cout << mask[0] << "." << mask[1] << "." << mask[2] << "." << mask[3] << "\n";

    return 0;
}
