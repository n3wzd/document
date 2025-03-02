# Open Street Map
**OpenStreetMap (OSM)**은 전 세계의 지리적 데이터를 오픈소스로 제공하는 프로젝트입니다. 이 프로젝트는 사용자가 직접 지도 데이터를 편집하고 공유할 수 있는 **자유로운 지도**를 만들기 위해 시작되었습니다. OSM은 **무료, 오픈소스, 사용자 참여형**으로, 누구나 지도를 만들고 수정할 수 있는 플랫폼입니다.

1. **자유로운 사용**: OSM은 모든 데이터를 **무료로** 제공하며, 상업적 용도로도 사용할 수 있습니다. 데이터는 Creative Commons Attribution-ShareAlike 라이선스(CC-BY-SA) 하에 제공됩니다. 이를 통해 누구나 지도 데이터를 사용할 수 있고, 자신만의 지도 서비스나 애플리케이션을 만들 수 있습니다.
2. **사용자 참여**: OpenStreetMap의 데이터는 전 세계의 사용자가 **편집하고 업데이트**할 수 있습니다. 사용자는 GPS 기기나 드론, 항공 사진 등을 통해 지리 정보를 추가하거나 수정할 수 있습니다.
3. **다양한 데이터**: OSM은 **도로**, **건물**, **상점**, **교통수단**, **지형지물**, **주소**, **시설물** 등 다양한 지리 정보를 포함하고 있습니다. 이 데이터는 매우 상세하고, 특정 지역에 대한 깊은 정보를 제공합니다.
4.  **API와 도구**: OSM은 지도 데이터를 **API**를 통해 제공하며, 이를 통해 개발자는 OSM 데이터를 활용하여 자신만의 지도 애플리케이션을 만들 수 있습니다.

## Overpass API
**Overpass API**는 OpenStreetMap (OSM) 데이터를 실시간으로 쿼리할 수 있는 API입니다. OpenStreetMap의 방대한 데이터를 실시간으로 요청하고 필요한 정보를 효율적으로 가져올 수 있게 해줍니다. Overpass API는 OSM의 원본 데이터를 필터링하여 특정 지역이나 조건에 맞는 데이터만 추출할 수 있기 때문에, 필요한 정보만 빠르게 가져올 수 있습니다.

1. **실시간 데이터 쿼리**: Overpass API는 OpenStreetMap의 데이터를 실시간으로 쿼리할 수 있게 해줍니다. 즉, OSM 서버에 직접 접근하여 필요한 데이터만 선택적으로 가져올 수 있습니다.
2. **필터링**: 특정 지역, 건물, 상점, 도로 등 OSM 데이터의 다양한 요소를 필터링하여 가져올 수 있습니다. 예를 들어, 특정 범위 내의 모든 상점 정보나 도로 정보를 가져올 수 있습니다.
3. **다양한 데이터 형식**: Overpass API는 데이터를 **XML**이나 **JSON** 형식으로 반환합니다. JSON 형식은 웹 애플리케이션에서 사용하기 편리하며, XML은 구조화된 데이터를 제공하기에 유용합니다.
4. **복잡한 쿼리 지원**: Overpass API는 다양한 쿼리 문법을 지원하여, 사용자가 필요한 데이터를 정교하게 필터링할 수 있습니다. 예를 들어, 특정 종류의 상점이나 시설물만 추출할 수 있습니다.

### 쿼리
- `node`: OSM의 노드 객체를 요청합니다. 노드는 위치를 나타내는 점입니다.
- `way`: OSM의 웨이 객체를 요청합니다. 웨이는 여러 노드를 연결하여 선형 객체를 만듭니다 (예: 도로, 경계선).
- `relation`: OSM의 관계 객체를 요청합니다. 여러 개의 노드나 웨이를 묶어 하나의 그룹을 형성합니다.
- `around`: 특정 위치를 중심으로 일정 반경 내의 데이터를 요청합니다.
- `out:json`: 결과 데이터를 JSON 형식으로 반환합니다.

```
http://overpass-api.de/api/interpreter?data=[out:json];(node["shop"](around:1000,37.7749,-122.4194););out;
```

이 예시는 **샌프란시스코**(위도: 37.7749, 경도: -122.4194) 주변 1000m 이내에 있는 모든 **상점** 정보를 가져옵니다.

### 출력
Overpass API에서 출력되는 데이터는 **JSON** 또는 **XML** 형식으로 반환됩니다. 일반적으로 **JSON** 형식이 더 많이 사용되며, 이를 웹 애플리케이션에서 쉽게 처리할 수 있습니다.

Overpass API에서 JSON 형식으로 데이터를 요청하면, 다음과 같은 형태로 응답을 받을 수 있습니다.
```
{
  "version": 0.6,
  "generator": "Overpass API 0.7.55.3 22f2cce1",
  "osm3s": {
    "timestamp_osm_base": "2025-01-01T12:00:00Z",
    "timestamp_areas_base": "2025-01-01T12:00:00Z",
    "copyright": "OpenStreetMap contributors"
  },
  "elements": [
    {
      "type": "node",
      "id": 123456789,
      "lat": 37.7749,
      "lon": -122.4194,
      "tags": {
        "name": "SuperMart",
        "addr:street": "Market Street",
        "addr:city": "San Francisco",
        "addr:postcode": "94103"
      }
    },
    {
      "type": "node",
      "id": 987654321,
      "lat": 37.7750,
      "lon": -122.4195,
      "tags": {
        "name": "Bakery Delight",
        "addr:street": "Mission Street",
        "addr:city": "San Francisco",
        "addr:postcode": "94103"
      }
    }
  ]
}
```
- `version`: API 버전 정보.
- `generator`: Overpass API 버전.
- `osm3s`: OpenStreetMap의 메타데이터, 타임스탬프와 저작권 정보 등을 포함.

#### `elements`
요청된 데이터의 실제 내용입니다. 이 예시에서는 `node` 객체가 포함되어 있습니다. 각 `node` 객체는 OSM의 노드 데이터를 나타내며, 상점의 위치, 이름, 주소 등의 정보를 포함합니다.

- `type`: 객체의 타입 (`node`, `way`, `relation` 등).
	- `node`: 단일 위치를 나타내는 점.
	- `way`: 여러 `node`들이 연결된 선형 객체. 도로, 자전거 도로, 보행자 도로 등 다양한 경로를 나타냅니다.
	- `relation`: 여러 `node`나 `way`들을 묶은 그룹.
- `id`: 해당 객체의 고유 ID.
- `lat`, `lon`: 노드의 위도 및 경도.
- `tags`: 노드에 대한 태그 정보. 예를 들어, 상점의 종류, 이름, 주소 등이 포함됩니다.

### 검색
Overpass API의 쿼리 언어를 사용하여 `amenity`나 `name` 등의 태그로 검색할 수 있습니다.

다음은 `amenity=kindergarten` 태그를 가진 모든 노드를 검색하는 예제입니다:
```
[out:json]; node["amenity"="kindergarten"]; out body;
```

### 테스트
다음 사이트에서 쿼리를 테스트할 수 있습니다.

> https://overpass-turbo.eu/

## Open Source Routing Machine
**OSRM (Open Source Routing Machine)**은 **OSM (OpenStreetMap)** 데이터를 기반으로 **빠르고 효율적인 경로 계산**을 제공하는 **오픈소스 라우팅 엔진**입니다. OSRM은 특히 **자동차**, **자전거**, **도보**와 같은 다양한 이동 수단에 대해 경로를 계산하는 데 사용됩니다.

1. **빠른 경로 계산**:
    - OSRM은 **경로 계산 속도가 매우 빠릅니다**. 이는 **미리 처리된 데이터**를 사용하여 경로를 계산하기 때문입니다. OSM 데이터를 **사전 처리**하여 경로 계산에 필요한 최단 경로를 빠르게 계산할 수 있습니다.
2. **OSM 기반**:
    - OSRM은 **OSM 데이터를 기반**으로 경로 계산을 수행합니다. OSM은 전 세계의 **도로 네트워크**를 포함한 **지리 정보**를 제공하므로, OSRM은 이를 활용하여 **정확한 경로**를 계산합니다.
3. **라우팅 옵션**:
    - OSRM은 **자동차**, **자전거**, **도보** 등 다양한 **이동 수단**에 맞는 경로를 계산할 수 있습니다. 또한 **고속도로**를 피하거나 **도로 속도 제한**을 고려하는 등의 고급 옵션을 제공합니다.
4. **다양한 API**:
    - OSRM은 **RESTful API**를 제공하여, 웹 애플리케이션에서 쉽게 경로를 계산할 수 있도록 해줍니다. API 호출을 통해 출발지와 목적지를 지정하면, 경로를 계산하여 **GeoJSON** 형식으로 응답을 반환합니다.
5. **경로 최적화**:
    - OSRM은 **최단 경로**를 계산할 뿐만 아니라, **여러 경로를 비교**하거나 **특정 조건에 맞는 경로**를 계산하는 기능도 제공합니다. 예를 들어, 특정 도로를 피하거나, **교차로**에서 우회전만 하도록 설정할 수 있습니다.


### 경로 계산
**경로 계산 API**는 두 지점(출발지와 목적지) 간의 최단 경로를 계산합니다. 기본적인 요청 형식은 다음과 같습니다:
```
http://router.project-osrm.org/route/v1/{profile}/{start_longitude},{start_latitude};{end_longitude},{end_latitude}?overview=false&steps=true
```

- **{profile}**: 이동 수단을 지정합니다. (예: **driving**, **cycling**, **walking**)
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

응답은 **GeoJSON 형식**으로 반환됩니다. 예를 들어, 위의 요청에 대한 응답은 다음과 비슷할 수 있습니다:

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
- **geometry**: 경로를 따라가는 선의 **좌표** 정보입니다.
- **distance**: 전체 경로의 거리(미터 단위).
- **duration**: 전체 경로의 소요 시간(초 단위).
