# Open Street Map
OpenStreetMap은 전 세계의 지리적 데이터를 오픈소스로 제공하는 프로젝트입니다. 이 프로젝트는 사용자가 직접 지도 데이터를 편집하고 공유할 수 있는 자유로운 지도를 만들기 위해 시작되었습니다. OSM은 무료, 오픈소스, 사용자 참여형으로, 누구나 지도를 만들고 수정할 수 있는 플랫폼입니다.

1. **자유로운 사용**: OSM은 모든 데이터를 무료로 제공하며, 상업적 용도로도 사용할 수 있습니다. 데이터는 Creative Commons Attribution-ShareAlike 라이선스(CC-BY-SA) 하에 제공됩니다. 이를 통해 누구나 지도 데이터를 사용할 수 있고, 자신만의 지도 서비스나 애플리케이션을 만들 수 있습니다.
2. **사용자 참여**: OpenStreetMap의 데이터는 전 세계의 사용자가 편집하고 업데이트할 수 있습니다. 사용자는 GPS 기기나 드론, 항공 사진 등을 통해 지리 정보를 추가하거나 수정할 수 있습니다.
3. **다양한 데이터**: OSM은 도로, 건물, 상점, 교통수단, 지형지물 등 다양한 지리 정보를 포함하고 있습니다. 이 데이터는 매우 상세하고, 특정 지역에 대한 깊은 정보를 제공합니다.
4.  **API와 도구**: OSM은 지도 데이터를 API를 통해 제공하며, 이를 통해 개발자는 OSM 데이터를 활용하여 자신만의 지도 애플리케이션을 만들 수 있습니다.

## Overpass API
**Overpass API**는 OpenStreetMap (OSM) 데이터를 실시간으로 쿼리할 수 있는 API입니다. OpenStreetMap의 방대한 데이터를 실시간으로 요청하고 필요한 정보를 효율적으로 가져올 수 있게 해줍니다. Overpass API는 OSM의 원본 데이터를 필터링하여 특정 지역이나 조건에 맞는 데이터만 추출할 수 있기 때문에, 필요한 정보만 빠르게 가져올 수 있습니다.

1. **실시간 데이터 쿼리**: Overpass API는 OpenStreetMap의 데이터를 실시간으로 쿼리할 수 있게 해줍니다. 즉, OSM 서버에 직접 접근하여 필요한 데이터만 선택적으로 가져올 수 있습니다.
2. **필터링**: 특정 지역, 건물, 상점, 도로 등 OSM 데이터의 다양한 요소를 필터링하여 가져올 수 있습니다. 예를 들어, 특정 범위 내의 모든 상점 정보나 도로 정보를 가져올 수 있습니다.
3. **다양한 데이터 형식**: Overpass API는 데이터를 XML이나 JSON 형식으로 반환합니다. JSON 형식은 웹 애플리케이션에서 사용하기 편리하며, XML은 구조화된 데이터를 제공하기에 유용합니다.
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

이 예시는 샌프란시스코(위도: 37.7749, 경도: -122.4194) 주변 1000m 이내에 있는 모든 상점 정보를 가져옵니다.

### 출력
Overpass API에서 출력되는 데이터는 JSON 또는 XML 형식으로 반환됩니다. 일반적으로 JSON 형식이 더 많이 사용되며, 이를 웹 애플리케이션에서 쉽게 처리할 수 있습니다.

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
