# Open Source Routing Machine
OSRM (Open Source Routing Machine)은 OSM (OpenStreetMap) 데이터를 기반으로 빠르고 효율적인 경로 계산을 제공하는 오픈소스 라우팅 엔진입니다. OSRM은 특히 자동차, 자전거, 도보와 같은 다양한 이동 수단에 대해 경로를 계산하는 데 사용됩니다.

1. **빠른 경로 계산**:
    - OSRM은 경로 계산 속도가 매우 빠릅니다. 이는 미리 처리된 데이터를 사용하여 경로를 계산하기 때문입니다. OSM 데이터를 사전 처리하여 경로 계산에 필요한 최단 경로를 빠르게 계산할 수 있습니다.
2. **OSM 기반**:
    - OSRM은 OSM 데이터를 기반으로 경로 계산을 수행합니다. OSM은 전 세계의 도로 네트워크를 포함한 지리 정보를 제공하므로, OSRM은 이를 활용하여 정확한 경로를 계산합니다.
3. **라우팅 옵션**:
    - OSRM은 자동차, 자전거, 도보 등 다양한 이동 수단에 맞는 경로를 계산할 수 있습니다. 또한 고속도로를 피하거나 도로 속도 제한을 고려하는 등의 고급 옵션을 제공합니다.
4. **다양한 API**:
    - OSRM은 RESTful API를 제공하여, 웹 애플리케이션에서 쉽게 경로를 계산할 수 있도록 해줍니다. API 호출을 통해 출발지와 목적지를 지정하면, 경로를 계산하여 GeoJSON 형식으로 응답을 반환합니다.
5. **경로 최적화**:
    - OSRM은 최단 경로를 계산할 뿐만 아니라, 여러 경로를 비교하거나 특정 조건에 맞는 경로를 계산하는 기능도 제공합니다. 예를 들어, 특정 도로를 피하거나, 교차로에서 우회전만 하도록 설정할 수 있습니다.


### 경로 계산
경로 계산 API는 두 지점(출발지와 목적지) 간의 최단 경로를 계산합니다. 기본적인 요청 형식은 다음과 같습니다:
```
http://router.project-osrm.org/route/v1/{profile}/{start_longitude},{start_latitude};{end_longitude},{end_latitude}?overview=false&steps=true
```

- **{profile}**: 이동 수단을 지정합니다. (예: driving, cycling, walking)
- **{start_longitude},{start_latitude}**: 출발지의 경도와 위도.
- **{end_longitude},{end_latitude}**: 목적지의 경도와 위도.
- **overview**: 경로의 세부 정보를 포함하며, 경로가 어떤 주요 지점들을 지나가는지에 대한 정보를 제공합니다. `false`로 설정하면 경로의 전체를 포함하지 않습니다. 
- **steps**: 경로의 각 단계(길 안내)를 포함할지 여부를 지정합니다. `true`로 설정하면 각 단계의 세부 정보가 포함됩니다.

자동차로 출발지 `(13.388860, 52.517037)`에서 목적지 `(13.397634, 52.529407)`로 가는 경로를 계산하려면, 다음과 같은 URL을 사용합니다:
```
http://router.project-osrm.org/route/v1/driving/13.388860,52.517037;13.397634,52.529407?overview=false&steps=true
```

- **출발지**: (13.388860, 52.517037)
- **목적지**: (13.397634, 52.529407)
- **이동 수단**: 자동차(`driving`)
- **overview**: 경로를 간략하게 표시하지 않음
- **steps**: 경로의 각 단계를 포함

응답은 GeoJSON 형식으로 반환됩니다. 예를 들어, 위의 요청에 대한 응답은 다음과 비슷할 수 있습니다:

```json
{
  "routes": [
    {
      "legs": [
        {
          "steps": [
            {
              "instruction": "Head west on Friedrichstr. toward Unter den Linden",
              "distance": 120,
              "duration": 60,
              "geometry": "..."
            },
            {
              "instruction": "Turn left onto Unter den Linden",
              "distance": 200,
              "duration": 120,
              "geometry": "..."
            }
            // 더 많은 단계...
          ]
        }
      ],
      "distance": 1800,
      "duration": 600
    }
  ]
}
```

- **steps**: 경로의 각 단계에 대한 지침과 거리, 소요 시간을 포함합니다.
- **geometry**: 경로를 따라가는 선의 좌표 정보입니다.
- **distance**: 전체 경로의 거리(미터 단위).
- **duration**: 전체 경로의 소요 시간(초 단위).
