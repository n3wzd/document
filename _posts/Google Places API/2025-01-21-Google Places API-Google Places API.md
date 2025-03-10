# Google Places API
Google Places API는 Google의 위치 기반 서비스 API 중 하나로, 사용자가 요청한 위치에 대한 장소 정보(예: 음식점, 관광지, 상점 등)를 제공하는 API입니다. 이 API는 위치 기반 데이터를 활용하여 특정 장소의 세부 정보(이름, 주소, 평점, 사진 등)와 같은 정보를 반환합니다.

- **장소 검색**: 특정 지역 내에서 장소를 검색할 수 있습니다. 예를 들어, "서울" 근처의 "음식점"을 찾거나 "카페"를 검색할 수 있습니다.
- **장소 세부 정보**: 각 장소에 대한 세부 정보를 조회할 수 있습니다. 예를 들어, 장소의 주소, 평점, 전화번호, 운영 시간 등을 포함한 정보를 얻을 수 있습니다.
- **장소 사진**: 장소에 대한 사진을 반환하여, 사용자가 해당 장소를 시각적으로 확인할 수 있습니다.
- **장소 유형**: 음식점, 호텔, 공원, 상점 등 다양한 장소 유형을 기준으로 검색할 수 있습니다.

## 요금
Google Places API는 무료 사용량과 유료 사용량이 있습니다. 무료 사용량에는 하루 일정량의 요청이 제공되며, 이를 초과하는 요청에 대해서는 요금이 부과됩니다. 요금은 호출 횟수와 API의 종류에 따라 다르므로, 사용량에 따라 요금이 달라질 수 있습니다.

**비용 (2025년 기준)**
- **Place Search (Nearby Search)**: 약 **$0.017 per request** (최대 20개의 장소 반환)
- **Place Details**: 약 **$0.003 per request**
- **Place Photos**: 약 **$0.007 per photo**
- **Place Autocomplete**: 약 **$0.002 per request**
- **Query Autocomplete**: 약 **$0.003 per request**

## API
Google Places API는 여러 가지 기능을 제공하는데, 주로 장소 검색과 세부 정보 조회에 사용됩니다. 다음은 주요 API와 그에 대한 쿼리 및 출력 정보입니다.

### Place Search API
이 API는 특정 위치 주변의 장소를 검색할 때 사용됩니다.

**입력:**
- **Endpoint**: `https://maps.googleapis.com/maps/api/place/nearbysearch/json`
- **필수 파라미터**:
    - `location`: 검색 기준이 되는 위치의 위도와 경도 (`lat,lng`)
    - `radius`: 검색 범위(미터 단위)
    - `type`: 장소 유형 (예: `restaurant`, `bar`, `park`, 등)
    - `key`: API 키
- **선택적 파라미터**:
    - `keyword`: 검색어로 장소를 필터링
    - `name`: 장소 이름으로 검색
    - `rankby`: 검색 결과 정렬 방식 (기본값은 `prominence`, `distance`로 설정 가능)
    - `opennow`: 현재 열려 있는 장소만 검색

**출력:**
- `results`: 장소에 대한 배열
    - `name`: 장소 이름
    - `place_id`: Google Places ID (세부 정보를 조회할 때 사용)
    - `geometry`: 위치 정보 (위도, 경도)
    - `types`: 장소 유형
    - `rating`: 평점 (존재할 경우)
    - `vicinity`: 장소의 주소
    - `photos`: 장소 사진 (존재할 경우)

```
{
  "results": [
    {
      "name": "Some Restaurant",
      "place_id": "ChIJN1t_tDeuEmsRUsoyG83frY4",
      "geometry": {
        "location": {
          "lat": -33.8670522,
          "lng": 151.1957362
        }
      },
      "types": ["restaurant", "food"],
      "rating": 4.5,
      "vicinity": "123 Some St, Sydney"
    }
  ],
  "status": "OK"
}
```

자세한 설명:
> https://developers.google.com/maps/documentation/javascript/places?hl=ko

### Place Details API
이 API는 `place_id`를 사용하여 특정 장소의 세부 정보를 가져옵니다.

**입력:**
- **Endpoint**: `https://maps.googleapis.com/maps/api/place/details/json`
- **필수 파라미터**:
    - `place_id`: `Place Search`에서 반환된 `place_id`
    - `key`: API 키
- **선택적 파라미터**:
    - `fields`: 반환할 필드 지정 (예: `name`, `address_component`, `geometry`, `photos`, `reviews` 등)

**출력:**
- `result`: 장소에 대한 세부 정보
    - `name`: 장소 이름
    - `place_id`: Google Places ID
    - `geometry`: 위치 정보 (위도, 경도)
    - `address_components`: 주소 세부 정보
    - `photos`: 장소 사진
    - `reviews`: 사용자 리뷰 (존재할 경우)
    - `rating`: 평점
    - `opening_hours`: 운영 시간 (존재할 경우)
    - `types`: 장소 유형

```
{
  "result": {
    "name": "Some Restaurant",
    "place_id": "ChIJN1t_tDeuEmsRUsoyG83frY4",
    "geometry": {
      "location": {
        "lat": -33.8670522,
        "lng": 151.1957362
      }
    },
    "address_components": [
      {
        "long_name": "Some St",
        "short_name": "Some St",
        "types": ["route"]
      },
      {
        "long_name": "Sydney",
        "short_name": "Sydney",
        "types": ["locality", "political"]
      }
    ],
    "photos": [
      {
        "photo_reference": "CmRaAAAAgsH5QJvCwGf6tx6D9I...",
        "height": 800,
        "width": 1200
      }
    ],
    "reviews": [
      {
        "author_name": "John Doe",
        "rating": 4,
        "text": "Great food!"
      }
    ],
    "rating": 4.5,
    "opening_hours": {
      "open_now": true
    },
    "types": ["restaurant", "food"]
  },
  "status": "OK"
}
```

장소 유형 목록:
> https://developers.google.com/maps/documentation/places/web-service/supported_types?hl=ko&_gl=1*smh0xr*_up*MQ..*_ga*Mjk0MDgwNzUzLjE3MzczNzA3OTc.*_ga_NRWSTWS78N*MTczNzM3MDc5Ny4xLjAuMTczNzM3MDgxOC4wLjAuMA..

### Place Autocomplete API
이 API는 사용자가 입력하는 검색어에 대해 자동완성 기능을 제공합니다.

**입력:**
- **Endpoint**: `https://maps.googleapis.com/maps/api/place/autocomplete/json`
- **필수 파라미터**:
    - `input`: 사용자가 입력한 검색어
    - `key`: API 키
- **선택적 파라미터**:
    - `types`: 검색할 장소 유형 (예: `geocode`, `establishment`, `address` 등)
    - `location`: 검색 기준이 되는 위치 (위도, 경도)
    - `radius`: 검색 범위(미터 단위)

**출력:**
- `predictions`: 예측된 장소 리스트
    - `description`: 장소 이름 및 주소
    - `place_id`: 장소 ID
    - `types`: 장소 유형

```
{
  "predictions": [
    {
      "description": "Some Restaurant, Sydney",
      "place_id": "ChIJN1t_tDeuEmsRUsoyG83frY4",
      "types": ["establishment", "geocode"]
    }
  ],
  "status": "OK"
}
```

### Place Photo API
이 API는 장소의 사진을 가져옵니다.

**입력:**
- **Endpoint**: `https://maps.googleapis.com/maps/api/place/photo`
- **필수 파라미터**:
    - `photoreference`: `Place Details API`에서 반환된 사진 참조
    - `key`: API 키
    - `maxwidth`: 사진의 최대 너비
- **선택적 파라미터**:
    - `maxheight`: 사진의 최대 높이

**출력:**
- 이미지 파일 (응답은 이미지 형태로 반환됨)
